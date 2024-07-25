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

void Traversal(struct Node *ptr)
{
    printf("\nThe elements in the Linked List are: \n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Inserting an element at first position:
struct Node * InsertAtFirst(struct Node * head, int newElement) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = newElement;
    ptr->next = head;
    return ptr;
}

// Inserting an element at in between at any index:
struct Node * InsertAtIndex(struct Node * head, int newElement, int index) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    int i = 0;
    while (i != index-1)
    {
        p = p->next;
        i++;
    }

    ptr->data = newElement;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// Inserting an element at at the end of Linked List:
struct Node *InsertAtEnd(struct Node *head, int newElement)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
       
    }

    ptr->data = newElement;
    ptr->next = NULL;
    p->next = ptr;

    return head;
}

// Inserting a node after a given Node
struct Node * InsertAfterNode( struct Node *head, struct Node * prevNode, int newElement ) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = newElement;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
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
    head->data = 5;
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

    int newElement;
    printf("Enter the new element to insert in the Linked List: ");
    scanf("%d", &newElement);
    head = InsertAtFirst(head, newElement);

    Traversal(head);

    int newElement1, index;
    printf("Enter the new element to insert in the Linked List: ");
    scanf("%d", &newElement1);
    printf("Enter the index where you want to insert in the new element in Linked List: ");
    scanf("%d", &index);
    head = InsertAtIndex(head, newElement1, index);

    Traversal(head);

    int newElement2;
    printf("Enter the new element to insert atthe end of the Linked List: ");
    scanf("%d", &newElement2);
    head = InsertAtEnd(head, newElement2);

    Traversal(head);

    printf("Inserting a new element after a given Node: (here, after second)");
    head = InsertAfterNode(head, second, 123);

    Traversal(head);
}