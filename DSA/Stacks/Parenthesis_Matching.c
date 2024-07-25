
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr) {
    if (ptr->top < 0)
        return 1;
    
    else
        return 0;
}

void push(struct stack *ptr, char element)
{
    if(ptr->top == ptr->size-1) {
        printf("Stack overflow\n");
    }
    else {
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

char pop(struct stack *ptr) {
    if(isEmpty(ptr)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int match(char open, char close) {
    if (open == '(' && close == ')')
        return 1;

    if (open == '{' && close == '}')
        return 1;

    if (open == '[' && close == ']')
        return 1;

    return 0;
}
 
int parenthesis_checker(char *exp, int length)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = length;
    s->top = -1;
    s->arr = (char *)malloc(sizeof(s->size * sizeof(char)));
    char popped_element;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(s, exp[i]);

        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
            if (isEmpty(s))
                return 0;      // 0  -->  unbalanced expression
            
            else{
                popped_element = pop(s);

                if (!match(popped_element, exp[i]))
                    return 0;
                }
        }
    }

    if (isEmpty(s))
        return 1;              //  1  -->  balanced expression

    else
        return 0;              //  0  -->  unbalanced expression
}


int main() {
    
    char expression[50];
    printf("Enter the mathematical expression: \n");
    scanf("%s", expression);

    int length = strlen(expression);

    if(parenthesis_checker( expression, length ))   // just the name of the array represents the address of the first element so that &expression[0] is passed to *exp
        printf("The given Mathematical expression is Balanced.\n");

    else
        printf("The given Mathematical expression is NOT Balanced.\n");

    return 0;
}