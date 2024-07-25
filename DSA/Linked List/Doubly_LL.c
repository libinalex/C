#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void DoubleTraversal(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr->next != NULL)
    {
        printf("The next element in Linked List is: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("The last element in Doubly Linked List is: %d\n", ptr->data);

    while (ptr != NULL)
    {
        printf("The previous element in Linked List is: %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 10;
    head->next = second;

    second->prev = head;
    second->data = 20;
    second->next = third;

    third->prev = second;
    third->data = 30;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 40;
    fourth->next = NULL;

    DoubleTraversal(head);
}