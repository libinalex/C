#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;

    return 0;
}

void push(int element, struct stack *ptr)
{
    if (isFull(ptr))
        printf("The stack is full. Stack Overflow !");
    
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("The stack is Empty. No element to remove from stack. Stack Underflow !");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return val;
    }
}


int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}


int precedence(char ch) {
    if (ch == '/' || ch == '*')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' )
        return 1;
    else
        return 0;
}

char *to_Postfix(char *infix, int len) {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = len+1;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));  //  stack to hold operators

    char *postfix = (char *)malloc(s->size * sizeof(char));
    int i = 0; // to scan infix expression
    int j = 0; // to fill postfix expression

    while (infix[i] != '\0')
    {
        if(!isOperator(infix[i])) {
            postfix[j] = infix[i];
            j++;
            i++;
        }

        else
        {
            if( precedence(infix[i]) > precedence(stackTop(s))) {
                push(infix[i], s);
                i++;
            }
            else
            {
                postfix[j] = pop(s);
                j++;
            }
            
        }
        
    }

    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }

    postfix[j] = '\0';
    return postfix;
}

int operate(int a, int b, char oper)
{
    int res = 0;
    switch (oper)
    {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break; // return result of evaluation
        case '/':
            res = a / b;
            break;
    }
    return res;
}

int main()
{
    char expression[50];
    printf("Enter the infix mathematical expression: \n");
    scanf("%s", expression);
    int length = strlen(expression);

    //char* postfix_expression[length + 1] = to_Postfix(expression, length);

    printf("The postfix expression is: %s\n", postfix_expression);
/*
    char oper;
    int operand1, operand2;
    int ctr = 0;
    int result[2]; // stack to keep storing results
    int rTop = -1; // top of result stack
    while (postfix_expression[ctr] != '\0')
    {
        oper = postfix_expression[ctr];
        if (oper >= '0' && oper <= '9')
            result[++rTop] = (int)(oper - '0'); // add numbers
        else
        { // if an operator is encountered than pop twice and push the result of operation to the stack
            operand1 = result[rTop--];
            operand2 = result[rTop--];
            result[++rTop] = operate(operand2, operand1, oper);
        }
        ctr++;
    }
*/
    return 0;
}
