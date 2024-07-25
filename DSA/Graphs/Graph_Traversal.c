// BFS(Breadth First Search) Implementation:
/*
#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int front, rear;
    int *arr;
};

int isFull(struct queue *que) {
    if (que->rear == que->size-1)
        return 1; 

    return 0;
}

int isEmpty(struct queue *que) {
    if(que->rear == que->front)
        return 1;

    return 0;
}

void Enque(struct queue *que, int data) {
    if(isFull(que))
        printf("The queue is Full, cannot insert element into the queue!\n");

    que->rear++;
    que->arr[que->rear] = data;
    //printf("Element Enqued: %d\n", que->arr[que->rear]);
}

int Deque(struct queue *que) {
    if(isEmpty(que))
        printf("The queue is Empty, cannot delete from the queue!");

    que->front++;
    return que->arr[que->front];
}

    // 0 - 1
    // | \ |
    // 3 - 2
    //  \ /
    //   4
    //  / \
    // 5   6

int main() {
    struct queue *que = (struct queue *)malloc(sizeof(struct queue));
    que->size = 10;
    que->arr = (int *)malloc(que->size * sizeof(int));
    que->front = que->rear = -1;

    int node, i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {                         // Multi-Dimensional Array to represent the graph.
        {0, 1, 1, 1, 0, 0, 0},      // node 0
        {1, 0, 1, 0, 0, 0, 0},      // node 1
        {1, 1, 0, 1, 1, 0, 0},      // node 2
        {1, 0, 1, 0, 1, 0, 0},      // node 3
        {0, 0, 1, 1, 0, 1, 1},      // node 4
        {0, 0, 0, 0, 1, 0, 0},      // node 5
        {0, 0, 0, 0, 1, 0, 0}};     // node 6

    printf("%d ", i);
    visited[i] = 1;
    Enque(que, i);      // Enque i for exploration

    while (!isEmpty(que))
    {
        node = Deque(que);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                Enque(que, j);
            }
            
        }
        
    }
    
}
*/

/**/
//Depth First Search

#include <stdio.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {             // Multi-Dimensional Array to represent the graph.
    {0, 1, 1, 1, 0, 0, 0},  // node 0
    {1, 0, 1, 0, 0, 0, 0},  // node 1
    {1, 1, 0, 1, 1, 0, 0},  // node 2
    {1, 0, 1, 0, 1, 0, 0},  // node 3
    {0, 0, 1, 1, 0, 1, 1},  // node 4
    {0, 0, 0, 0, 1, 0, 0},  // node 5
    {0, 0, 0, 0, 1, 0, 0}}; // node 6


//     0 - 1
//     | \ |
//     3 - 2
//      \ /
//       4
//      / \
//     5   6


void DFS(int i) {
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (a[i][j] == 1 && visited[j] == 0)
        {
            DFS(j);
        }
    }
}

int main()
{
    DFS(5);
    return 0;
}