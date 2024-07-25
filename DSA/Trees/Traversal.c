
/*
           2
         /  \
        1    4
       / \    \
      7   5    3   


Preorder:  Root -> Left Subtree -> Right Subtree    =>   2 1 7 5 4 3
Postorder:  Left Subtree -> Right Subtree -> Root   =>   7 2 1 3 4 5
Inorder:  Left Subtree -> Root -> Right Subtree     =>   7 1 2 5 4 3
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* CreateNode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void PreorderTraversal(struct node *ptr) {
    if (ptr != NULL)
    {
        printf("%d ", ptr->data);
        PreorderTraversal(ptr->left);
        PreorderTraversal(ptr->right);
    }
}

void PostorderTraversal(struct node *ptr) {
    if(ptr != NULL) {
        PostorderTraversal(ptr->left);
        PostorderTraversal(ptr->right);
        printf("%d ", ptr->data);
    }
}

void InorderTraversal(struct node *ptr) {
    if (ptr != NULL)
    {
        InorderTraversal(ptr->left);
        printf("%d ", ptr->data);
        InorderTraversal(ptr->right);
    }
    
}

int main()
{
    struct node *root = CreateNode(2);
    struct node *n1 = CreateNode(1);
    struct node *n2 = CreateNode(4);
    struct node *n3 = CreateNode(7);
    struct node *n4 = CreateNode(5);
    struct node *n6 = CreateNode(3);

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->left = NULL;
    n2->right = n6;

    printf("Preorder Traversal: \n");
    PreorderTraversal(root);

    printf("\n\nPostorder Traversal: \n");
    PostorderTraversal(root);

    printf("\n\nInorder Traversal: \n");
    InorderTraversal(root);

    return 0;
}