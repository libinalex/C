

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node * CreateNode(int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void InorderTraversal(struct node * ptr) {
    if (ptr != NULL)
    {
        InorderTraversal(ptr->left);
        printf("%d ", ptr->data);
        InorderTraversal(ptr->right);
    }
}

// Recursive Search:
void Search(int key, struct node *ptr) {
    if (ptr == NULL)
        printf("No! the given key, %d is not present in the Binary Search Tree.\n", key);
    
    if(key == ptr->data) 
        printf("Yes! the given key, %d is present in the Binary search tree.\n", key);
    
    else if(key < ptr->data) 
        Search(key, ptr->left);

    else 
        Search(key, ptr->right);
}

// Iterative Search
void Search_Iterative(int key, struct node *ptr) {
    while (ptr != NULL)
    {
        if(key == ptr->data){
            printf("Yes! the given key, %d is present in the Binary search tree.\n", key);
            return;
        }

        else if(key < ptr->data)
            ptr = ptr->left;
        
        else
            ptr = ptr->right;
    }
    printf("No! the given key, %d is not present in the Binary Search Tree.\n", key);
}


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

    n2->left = n5;
    n5->left = n8;
    

}