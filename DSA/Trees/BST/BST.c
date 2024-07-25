/*
Properties:-
1. All nodes of the left sub-tree are lesser.
2. All nodes of the right sub-tree are grater.
3. Left and right sub-trees are also Binary Search Trees.
4. There are no duplicate nodes.
5. Inorder Traversal of a BST gives an ascending sorted array.

        5
     /    \
    3      8
   / \    / \
  1   4  6   9

*/
/*
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node * createNode(int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void InorderTraversal(struct node *ptr) {
    if (ptr != NULL)
    {
        InorderTraversal(ptr->left);
        printf("%d ", ptr->data);
        InorderTraversal(ptr->right);
    }
}

int CheckBST(struct node *ptr) {
    static struct node *prev = NULL;
    if (ptr != NULL)
    {
        if(!CheckBST(ptr->left)) {
            return 0;
        }
        if(prev != NULL && ptr->data <= prev->data) {
            return 0;
        }
        prev = ptr;
        return (CheckBST(ptr->right));
    }
    else
        return 1;
}

void Minimum(struct node *ptr){
    while (ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    printf("The minimum element in the BST is: %d\n", ptr->data);
}

void Maximum(struct node *ptr){
    while (ptr->right != NULL)
    {
        ptr = ptr->right;
    }
    printf("The maximum element in the BST is: %d\n", ptr->data);
}

int main() {
    struct node *root = createNode(5);
    struct node *n1 = createNode(3);
    struct node *n2 = createNode(8);
    struct node *n3 = createNode(1);
    struct node *n4 = createNode(4);
    struct node *n5 = createNode(6);
    struct node *n6 = createNode(9);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;

    printf("\nThe Inorder Traversal of the given binary tree is: \n");
    InorderTraversal(root);

    if (CheckBST(root)){
        printf("\nYES! The given binary tree is a Binary Search Tree.\n");
    }
    else
        printf("\nNO! The given binary tree is NOT a Binary Search Tree.\n");

    Minimum(root);
    Maximum(root);
}
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
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

int CheckBST(struct node *ptr)
{
    static struct node *prev = NULL;
    if (ptr != NULL)
    {
        if (!CheckBST(ptr->left))
        {
            return 0;
        }
        if (prev != NULL && ptr->data <= prev->data)
        {
            return 0;
        }
        prev = ptr;
        return (CheckBST(ptr->right));
    }
    else
        return 1;
}

struct node *creatBST(struct node *ptr, int key)
{
    /* If the tree is empty, return a new node */
    if (ptr == NULL)
        return createNode(key);

    /* Otherwise, recur down the tree */
    if (key < ptr->data)
        ptr->left = creatBST(ptr->left, key);
    else if(key > ptr->data)                    // not just else to avoid duplicate values
        ptr->right = creatBST(ptr->right, key);

    /* return the (unchanged) node pointer */
    return ptr;
}

struct node * Search(int key, struct node * root) {
    if(root == NULL)
        return NULL;
    
    if (key < root->data)
        return Search(key, root->left);

    else if (key > root->data)
        return Search(key, root->right);

    else
        return root;
}

/*
        5
     /    \
    3      8
   / \    / \
  1   4  6   9

*/

int main()
{
    struct node *root = NULL;
    root = creatBST(root, 3);
    root = creatBST(root, 9);
    root = creatBST(root, 1);
    root = creatBST(root, 5);
    root = creatBST(root, 8);
    root = creatBST(root, 6);
    root = creatBST(root, 4);


    printf("\nThe Inorder Traversal of the given binary tree is: \n");
    InorderTraversal(root);

    if (CheckBST(root))
    {
        printf("\nYES! The given binary tree is a Binary Search Tree.\n");
    }
    else
        printf("\nNO! The given binary tree is NOT a Binary Search Tree.\n");


    int search = 7;
    if(Search(search, root))
        printf("The key %d is present in the BST.", search);

    else
        printf("The key %d is NOT present in the BST.", search);
}