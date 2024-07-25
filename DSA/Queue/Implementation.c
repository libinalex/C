#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void Traversal(struct queue *q) {
    printf("The elements in queue are: \n");

    for (int i = q->front+1; i <= q->rear; i++)
    {
        printf("Element: %d\n", q->arr[i]);
    }
    printf("\n");
}

int isFull(struct queue *q) {
    if (q->rear == q->size-1)
        return 1;
    
    else 
        return 0;
}

int isEmpty(struct queue *q)
{
    if (q->rear == q->front)
        return 1;

    else
        return 0;
}

void enque(struct queue *q, int data) {
    if(isFull(q))
        printf("The queue is Full! Can't insert new element.\n");

    else {
        q->rear++;
        q->arr[q->rear] = data;
    }
    
}

int deque(struct queue *q) {
    if(isEmpty(q)){
        printf("The queue is Empty! Can't delete element from queue.\n");
        return 0;
    }

    else {
        q->front++;
        int val = q->arr[q->front];
        return val;
    }
    
}

int main() {

    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 5;
    q->rear = q->front = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    if (isEmpty(q))
        printf("The queue is Empty!\n");

    if (isFull(q))
        printf("The queue is Full!\n");

    printf("Inserting elements in Queue \n");
    enque(q, 10);
    enque(q, 20);
    enque(q, 30);
    enque(q, 40);
    enque(q, 50);

    Traversal(q);

    if (isEmpty(q))
        printf("The queue is Empty!\n");

    if (isFull(q))
        printf("The queue is Full!\n");

    printf("Removing element from Queue: \n");
    printf("The deleted element from ques is: %d\n", deque(q));
    printf("The deleted element from ques is: %d\n", deque(q));
    printf("The deleted element from ques is: %d\n", deque(q));
    printf("The deleted element from ques is: %d\n", deque(q));
    printf("The deleted element from ques is: %d\n", deque(q));

    enque(q, 67);

    if (isEmpty(q))
        printf("The queue is Empty!\n");

    if (isFull(q))
        printf("The queue is Full!\n");

    Traversal(q);
    return 0;
}