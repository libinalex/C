/*
isomorphic
Two trees T1 and T2 are said to be isomorphic if T1 can be transformed into T2 by swapping left and right children of the nodes in T1.  Given two trees T are isomorphic.






Given two full Binary Tree (BT), write a program to check whether they are isomorphic or not.

sample input:

7 // no. of nodes in the tree
// tree 1
30
20
40
15
25
35
45

//tree 2
30
40
20
45
35
25
15


7
30
20
40
15
25
35
45
30
40
20
45
35
25
15
output:
Isomorphic
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
    ptr->right = NULL;
    ptr->left = NULL;
    return ptr;
}

struct node *createBST(struct node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = createBST(root->left, data);

    else
        root->right = createBST(root->right, data);

    return root;
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

int isIsomorphic(struct node *ptr1, struct node *ptr2)
{
    if (ptr1 == NULL && ptr2 == NULL)
        return 1;

    if (ptr1 == NULL || ptr2 == NULL)
        return 0;

    if (ptr1->data != ptr2->data)
        return 0;

    return (isIsomorphic(ptr1->left, ptr2->left) && isIsomorphic(ptr1->right, ptr2->right)) ||
           (isIsomorphic(ptr1->left, ptr2->right) && isIsomorphic(ptr1->right, ptr2->left));
}

int main()
{
    struct node *root1 = NULL;
    int data, num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &data);
        root1 = createBST(root1, data);
    }

    struct node *root2 = NULL;
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &data);
        root2 = createBST(root2, data);
    }

    if (isIsomorphic(root1, root2))
        printf("Isomorphic");
    else
        printf("Not Isomorphic");
}

/*
Full BST
A Full Binary Tree is defined as binary tree in which all nodes have either 0 children or 2 children. For example, the given BT is full Binary Tree

Consider a game. The participant should spell the numbers one by one; utilizing this, the player should create a Binary Search Tree (BST). To the maximum 9 words can be spelled.

Write a program to check whether the created BST forms full BST or not. If it forms full BST, display “Congratulations” otherwise display “Better luck next time”.

Sample input:

30
20
40
35
45
32
37
15
23

Output:
Congratulations

Input:
30
20
35
10
25
5
45
40
55

Expected output
Better Luck Next Time
*/
/*
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
    ptr->right = NULL;
    ptr->left = NULL;
    return ptr;
}

struct node *createBST(struct node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = createBST(root->left, data);

    else
        root->right = createBST(root->right, data);

    return root;
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

int checkFullBST(struct node *ptr) {
    if (ptr == NULL)
        return 1;

    if (ptr->left == NULL && ptr->right == NULL)
        return 1;

    if ((ptr->left) && (ptr->right))
        return (checkFullBST(ptr->left) && checkFullBST(ptr->right));

    return 0;
}

int main()
{
    struct node *root = NULL;
    int data;
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &data);
        root = createBST(root, data);
    }

    InorderTraversal(root);

    if(checkFullBST(root))
        printf("Congratulations");

    else
        printf("Better luck next time");
}
*/

