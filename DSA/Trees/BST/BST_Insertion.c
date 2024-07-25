#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *CreateNode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void InorderTraversal(struct node *ptr)
{
    if (ptr != NULL)
    {
        InorderTraversal(ptr->left);
        printf("%d ", ptr->data);
        InorderTraversal(ptr->right);
    }
}

void Insert(int key, struct node *ptr) {
    struct node *prev = NULL;
    while (ptr != NULL)
    {
        prev = ptr;
        if(ptr->data == key){
            printf("The given key is already present in the BST.\n");
            return;
        }

        else if(key < ptr->data){
            ptr = ptr->left;
        }

        else
            ptr = ptr->right;
    }
    struct node *n = CreateNode(key);
    if(key < prev->data)
        prev->left = n;

    else
        prev->right = n;
}

/*
           8
        /    \
       3      10
      / \      \
     1   6      14
        / \    /
       4   7  13
*/

int main()
{
    struct node *root = CreateNode(8);
    struct node *n1 = CreateNode(3);
    struct node *n2 = CreateNode(10);
    struct node *n3 = CreateNode(1);
    struct node *n4 = CreateNode(6);
    struct node *n5 = CreateNode(14);
    struct node *n6 = CreateNode(4);
    struct node *n7 = CreateNode(7);
    struct node *n8 = CreateNode(13);

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n4->left = n6;
    n4->right = n7;

    n2->right = n5;
    n5->left = n8;

    InorderTraversal(root);
    int key = 15;
    printf("\n\nInserting element %d in the BST: \n", key);
    Insert(key, root);
    InorderTraversal(root);
}