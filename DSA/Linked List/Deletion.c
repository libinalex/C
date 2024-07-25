

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; //  ---->  Self Referencing Structure
};

void Traversal(struct Node *ptr)
{
    printf("\nThe elements in the Linked List are: \n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Deleting a node from the start of Linked List:
struct Node * DeleteFromStart(struct Node *head) {
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Deleting a node at a given index of Linked List:
struct Node * DeleteAtIndex(struct Node *head, int index) {
    struct Node *ptr1 = head;
    int i = 0;
    while (i != index-1)
    {
        ptr1 = ptr1->next;
        i++;
    }
    struct Node *ptr2 = ptr1->next;
    ptr1->next = ptr2->next;
    free(ptr2);

    return head;
}

// Deleting a node from the end of Linked List:
struct Node * DeleteFromLast(struct Node *head) {
    struct Node *ptr1 = head;
    struct Node *ptr2 = head->next;
    while (ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    ptr1->next = NULL;
    free(ptr2);

    return head;
}

// Deleting a node with a given value from the Linked List:
struct Node * DeleteValue(struct Node *head, int value) {
    struct Node *ptr1 = head;
    struct Node *ptr2 = head->next;
    while (ptr2->data != value && ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    if (ptr2->data == value)
    {
        ptr1->next = ptr2->next;
        free(ptr2);
    }
    else
        printf("The value you want to delete does not belong to the Linked List!\n");
 
    return head;
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

    // head = DeleteFromStart(head);
    // Traversal(head);

    // head = DeleteAtIndex(head, 2);
    // Traversal(head);

    // head = DeleteFromLast(head);
    // Traversal(head);

    head = DeleteValue(head, 10);
    Traversal(head);
}