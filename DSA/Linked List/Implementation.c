/*
Linked List can be implemented using Structure in C language.
*/

/*
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;          //  ---->  Self Referencing Structure
};

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;


    // Dynamically allocate memory for nodes of the Linked List in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second Nodes:
    head->data = 7;
    head->next = second;

    // Link second and third Nodes:
    second->data = 10;
    second->next = third;

    // Therminating the List at the third Node:
    third->data = 15;
    third->next = NULL;

}

*/


/*
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; //  ---->  Self Referencing Structure
};

void Traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int num;
    printf("Enter the number of elements in Linked List: ");
    scanf("%d", &num);

    struct Node LL[num];

    int i = 0;
    while (i < num)
    {
        
        struct Node *LL[i];
        LL[i] = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter number %d to store in Linked List: ", i+1);
        scanf("%d", &LL[i]->data);
        if (i == num-1)
            LL[i]->next = NULL;
        
        else
            LL[i]->next = LL[i+1];
        
        i++;
    }

    Traversal(LL);
}

*/


/*
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; //  ---->  Self Referencing Structure
};

void Traversal(struct Node *ptr)
{
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
    printf("Enter the 1st element: ");
    scanf("%d", &head->data);
    head->next = second;

    // Link second and third Nodes:
    printf("Enter the 2nd element: ");
    scanf("%d", &second->data);
    second->next = third;

    // Link third and fourth Nodes:
    printf("Enter the 3rd element: ");
    scanf("%d", &third->data);
    third->next = fourth;

    // Therminating the List at the fourth Node:
    printf("Enter the last element: ");
    scanf("%d", &fourth->data);
    fourth->next = NULL;

    printf("\nThe elements in the Linked List are: \n");

    Traversal(head);
}
*/
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void Traverse(struct node *head) {
    struct node *iter = head;
    printf("The elements in the Linked list are: ");
    while(iter != NULL) {
        printf("%d ", iter->data);
        iter = iter->next;
    }
}

int main() {
    struct node *head, *newnode, *temp;
    head = NULL;
    int n;
    printf("Enter the number of elements you want to insert in the Linked List: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
            head = temp = newnode;
        
        else {
            temp->next = newnode;
            temp = newnode;
        }     
    }

    Traverse(head);

    return 0;
}

