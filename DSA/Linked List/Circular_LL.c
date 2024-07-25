#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void CircularTraversal(struct Node *head) {
    struct Node *ptr = head;

    do
    {
        printf("The element in Linked List is: %d\n", ptr->data);
        ptr = ptr->next;

    } while (ptr != head);
    
}

struct Node * InsertionAtBeginning(struct Node *head, int newElement) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr1 = head->next;
    ptr->data = newElement;

    while (ptr1->next != head)
    {
        ptr1 = ptr1->next;
    }
    ptr1->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}

int main() {
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = head;

    CircularTraversal(head);

    head = InsertionAtBeginning(head, 5);
    head = InsertionAtBeginning(head, 0);
    printf("The Linked List after insertion of element at beginning is: \n");
    CircularTraversal(head);


}