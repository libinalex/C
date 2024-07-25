// Grammar
//  E -> E + T | T
//  T -> T * F | F
//  F -> (E) | i

// Eliminating Left Recursion
//   E -> TD
//   D -> +TD | e
//   T -> FU
//   U -> *FU | e
//   F -> (E) | i

// State Substitutes
//  E' = D
//  T' = U


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1000

typedef struct {
    int top;
    char items[STACK_SIZE];
} Stack;

void push(Stack* stack, char item) {
    stack->items[++stack->top] = item;
}

char pop(Stack* stack) {
    return stack->items[stack->top--];
}

char tos(Stack* stack)
{
    return stack->items[stack->top];
}

void initialize(Stack *stack)
{
    stack->top = -1;
    push(stack, '$');
}

void predictiveParsing(const char* input, const char* parsingTable[][6]) {
    Stack stack;
    initialize(&stack);

    push(&stack, 'E');

    int inputIndex = 0;
    char currentSymbol = input[inputIndex];

    while (stack.top != -1) {
        char stackTop = pop(&stack);

        if (stackTop == currentSymbol) {
            if (currentSymbol == '$') {
                printf("Parsing Successful\n");
                return;
            }
            currentSymbol = input[++inputIndex];
        } else {
            int row, column;

            switch (stackTop) {
                case 'E':
                    row = 0;
                    break;
                case 'D':
                    row = 1;
                    break;
                case 'T':
                    row = 2;
                    break;
                case 'U':
                    row = 3;
                    break;
                case 'F':
                    row = 4;
                    break;
                default:
                    printf("Invalid symbol\n");
                    printf("Parsing Failed\n");
                    exit(EXIT_FAILURE);
            }

            switch (currentSymbol) {
                case 'i':
                    column = 0;
                    break;
                case '+':
                    column = 1;
                    break;
                case '*':
                    column = 2;
                    break;
                case '(':
                    column = 3;
                    break;
                case ')':
                    column = 4;
                    break;
                case '$':
                    column = 5;
                    break;
                default:
                    printf("Invalid input symbol\n");
                    exit(EXIT_FAILURE);
            }

            const char* production = parsingTable[row][column];
            
            printf("%s\n", production);
            if (strcmp(production, "") != 0)
            {
                    int length = strlen(production);
                    for (int i = length - 1; i >= 3; i--)
                    {
                        push(&stack, production[i]);
                    }
            }
            else{
                printf("Parsing Failed\n");
                exit(EXIT_FAILURE);
            }

            if (tos(&stack) == 'e')
                pop(&stack);
        }
    }

    printf("Parsing Failed\n");
}

int main() {
    const char* parsingTable[5][6] = {
        {"E->TD", "", "", "E->TD", "", ""},
        {"", "D->+TD", "", "", "D->e", "D->e"},
        {"T->FU", "", "", "T->FU", "", ""},
        {"", "U->e", "U->*FU", "", "U->e", "U->e"},
        {"F->i", "", "", "F->(E)", "", ""}
    };

    char input[1000];
    printf("Enter the input string: ");
    scanf("%s", input);

    printf("Parsing Input: %s\n", input);
    predictiveParsing(input, parsingTable);

    return 0;
}


/*
i+i*i+i$
i*i+*i$
)i+i*i$
((i+i)*i$
*/