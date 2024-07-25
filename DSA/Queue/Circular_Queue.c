#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void Traversal(struct CircularQueue *q)
{
    printf("The elements in CircularQueue are: \n");

    for (int i = q->front + 1; i <= q->rear; i= (i+1)%q->size)
    {
        printf("Element: %d\n", q->arr[i]);
    }
    printf("\n");
}

int isFull(struct CircularQueue *q)
{
    if ((q->rear+1)%q->size == q->front)
        return 1;

    else
        return 0;
}

int isEmpty(struct CircularQueue *q)
{
    if (q->rear == q->front)
        return 1;

    else
        return 0;
}

void enque(struct CircularQueue *q, int data)
{
    if (isFull(q))
        printf("The CircularQueue is Full! Can't insert new element.\n");

    else
    {
        q->rear = (q->rear+1)%q->size;
        q->arr[q->rear] = data;
        printf("Enqueued element: %d\n", q->arr[q->rear]);
    }
}

int deque(struct CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("The CircularQueue is Empty! Can't delete element from CircularQueue.\n");
        return 0;
    }

    else
    {
        q->front = (q->front+1)%q->size;
        int val = q->arr[q->front];
        return val;
    }
}

int main()
{

    struct CircularQueue *q = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    q->size = 5;
    q->rear = q->front = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    if (isEmpty(q))
        printf("The CircularQueue is Empty!\n");
    
    if (isFull(q))
        printf("The CircularQueue is Full!\n");

    printf("Inserting elements in CircularQueue \n");
    enque(q, 10);
    enque(q, 20);
    enque(q, 30);
    enque(q, 40);
    // enque(q, 50);

    // Traversal(q);

    if (isEmpty(q))
        printf("The CircularQueue is Empty!\n");

    if (isFull(q))
        printf("The CircularQueue is Full!\n");

    printf("Removing element from CircularQueue: \n");
    printf("The deleted element from ques is: %d\n", deque(q));
    printf("The deleted element from ques is: %d\n", deque(q));
    printf("The deleted element from ques is: %d\n", deque(q));
    printf("The deleted element from ques is: %d\n", deque(q));

    if (isEmpty(q))
        printf("The CircularQueue is Empty!\n");

    if (isFull(q))
        printf("The CircularQueue is Full!\n");


    // Traversal(q);

    enque(q, 50);
    enque(q, 60);

    if (isEmpty(q))
        printf("The CircularQueue is Empty!\n");

    if (isFull(q))
        printf("The CircularQueue is Full!\n");
    // Traversal(q);



    return 0;
}