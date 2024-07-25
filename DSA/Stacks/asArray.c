
#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr) {
    if( ptr->top == -1) {
        return 1;
    }

    else {
        return 0;
    }
}

int isFull(struct stack *ptr) {
    if( ptr->top == ptr->size-1) {
        return 1;
    }

    else {
        return 0;
    }
}

void push(int element, struct stack *ptr) {
    if (isFull(ptr)) {
        printf("The stack is full. Stack Overflow !");
    }

    else {
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

int pop(struct stack *ptr) {
    if(isEmpty(ptr)) {
        printf("The stack is Empty. No element to remove from stack. Stack Underflow !");
        return -1;
    }
    else {
        int val = ptr->arr[ptr->top];
        ptr->top = ptr->top-1;
        return val;
    }
}

int peek(struct stack *ptr, int i) {
    if (ptr->top-i+1 < 0) {
        printf("You have peeked a number out of bound!");
        return -1;
    }
    else {
        return ptr->arr[ptr->top - i + 1];
    }
}

int stackTop(struct stack *ptr) {
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr) {
    return ptr->arr[0];
}

void display(struct stack *ptr)
{
    printf("The array is: \n");
    for (int i = 0; i <= ptr->top; i++)
    {
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
}

int main() {
    // struct stack s;
    // s.size = 50;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    printf("Enter the max size of stack: ");
    scanf("%d", &s->size);
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    if (isEmpty(s)) {
        printf("The stack is Empty!\n");
    }
    else {
        printf("The stack is not Empty!\n");
    }

    int element;
    printf("Enter the element to push in the stack: ");
    scanf("%d", &element);

    push(element, s);

    push(12, s);
    push(24, s);
    push(16, s);
    push(4, s);
    display(s);

    pop(s);
    printf("After pop: \n");
    display(s);

    printf("Peeking element 2 from top: %d\n", peek(s, 2));

    printf("The topmost element in the stack is: %d\n", stackTop(s));

    printf("The bottom most element in the stack is: %d\n", stackBottom(s));

    return 0;
}