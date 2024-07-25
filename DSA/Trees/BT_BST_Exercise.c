/*
1. BT- sum
Given 'n' nodes, construct a Binary Tree (BT). compute the sum of values of nodes at each level of Binary Tree. 
In the tree given below, sum of values of nodes at level 0 is 1, level 1 is 16, level 2 is 17, level 3 is 21.

sample input:
n  // number of nodes
n1
n2
...
nn

output
s0  // sum at level 0
s1  // sum at level  1
...
sh // sum at level h

Input
5
1
2
3
5
6

Expected output
1
5
11
*/





/*
2. BST - height
Given 'n' nodes, construct Binary Search Tree (BST) and find the height of the constructed BST. 
Consider the first node as root node.

input format:
n    // number of nodes
n1
n2
....
nn

output format:
h  // height of tree

sample input:
8
25
13
32
9
45
27
7
2

output:
4
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* Compute the "maxDepth" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int Height(struct node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = Height(node->left);
        int rDepth = Height(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

struct node *createNode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);

    else
        root->right = insert(root->right, data);

    return root;
}

int main()
{
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node *root = NULL;
    printf("Enter the nodes of BST: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Height of tree is %d", Height(root));

    return 0;
}

/*
3. BST - sort
Given n nodes, construct Binary Search Tree. Preform the following operations on constructed BST.
a) find the max and min value in BSt
b) Write a program to print the elemnts of BST in ascending order.

sample input:
n  // number of nodes
n1
n2
..
nn

output:
max  // max element in BST
min  // min element in BST
elements in sorted order


Input
8
25
13
32
9
45
27
7
2
Expected output
45
2
2
7
9
13
25
27
32
45
*/
/*
#include<stdio.h>
#include<stdlib.h>

struct node{
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

struct node *insert(struct node *root, int data) {
    if(root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    
    else
        root->right = insert(root->right, data);

    return root;
}

void Minimum(struct node *root) {
    while (root->left != NULL)
    {
        root = root->left;
    }
    printf("The minimum element in the BST is %d\n", root->data);
}

void Maximum(struct node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    printf("The maximum element in the BST is %d\n", root->data);
}

void InorderTraversal(struct node* ptr) {
    if (ptr != NULL)
    {
        InorderTraversal(ptr->left);
        printf("%d\n", ptr->data);
        InorderTraversal(ptr->right);
    }
    
}

int main() {
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node *root = NULL;
    printf("Enter the nodes of BST: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    Maximum(root);
    Minimum(root);
    InorderTraversal(root);
}
*/