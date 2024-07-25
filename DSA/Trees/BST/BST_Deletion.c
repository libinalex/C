/*
Case 1: The node is a leaf node.
Case 2: The node is a non-leaf node.
Case 3: The node is a root node.


           8
        /    \
       3      10
      / \      \
     1   6      14
        / \    /
       4   7  13

*/

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

/*
           8
        /    \
       3      10
      / \      \
     1   6      14
        / \    /
       4   7  13

// inorder Predecessor = Right-most child of the left sub-tree
// inorder Sucessor = Lest-most child of the right sub-tree
*/
struct node *inOrderPredecessor(struct node *ptr)
{
    ptr = ptr->left;
    while (ptr->right != NULL)
    {
        ptr = ptr->right;
    }
    return ptr;
}


struct node * Delete(int key, struct node *ptr) {
    
    // Base condition for recursion
    if (ptr == NULL)
        return NULL;

    if (ptr->left == NULL && ptr->right == NULL){       // Condition for leaf Node
        free(ptr);
        return NULL;
    }

    // Search for the node to be deleted
    if(key < ptr->data)
        ptr->left = Delete(key, ptr->left);

    else if(key > ptr->data)
        ptr->right = Delete(key, ptr->right);

    // Deletion strategy when the node is found
    else{    // key == ptr->data  // We have found the node to be deleted
        struct node *inPre = inOrderPredecessor(ptr); // We could also replace it with inOrder successor, In that case we would have to delete ptr->right
        ptr->data = inPre->data;
        ptr->left = Delete(inPre->data, ptr->left); 
    }
    return ptr;
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

    n2->right = n5;
    n5->left = n8;

    int key = 8;
    InorderTraversal(root);
    printf("\nDeleting node %d from the BST...\n", key);
    Delete(key, root);
    InorderTraversal(root);
    printf("\nThe data in place of the deleted node now is: %d\n", root->data);
}