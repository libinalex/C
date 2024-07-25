/*
Linked List can be implemented using Structure in C language.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; //  ---->  Self Referencing Structure
};

void Traversal(struct Node* ptr) {
    printf("\nThe elements in the Linked List are: \n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Dynamically allocate memory for nodes of the Linked List in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second Nodes:
    head->data = 7;
    head->next = second;

    // Link second and third Nodes:
    second->data = 10;
    second->next = third;

    // Link third and fourth Nodes:
    third->data = 15;
    third->next = fourth;

    // Therminating the List at the fourth Node:
    fourth->data = 20;
    fourth->next = NULL;

    Traversal(head);
}