#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int height(struct node *n)
{
    if (n == NULL)
        return 0;
    else
        return 1 + max(height(n->left), height(n->right));
}

struct node *newNode(int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
    temp->left = temp->right = NULL;
    temp->height = 0;
    return temp;
}

struct node *rightRotate(struct node *y)
{
    // nodes that change position
    // hence save those nodes in variables
    struct node *x = y->left;
    struct node *t2 = x->right;

    // change the places of those nodes
    x->right = y;
    y->left = t2;

    // since only x and y change their positions which aren't leaf nodes, hence update their heights
    y->height = height(y);
    x->height = height(x);

    // new root is now x
    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = height(x);
    y->height = height(y);

    return y;
}

int getBalance(struct node *n)
{
    if (n == NULL)
        return 0;
    else
        return height(n->left) - height(n->right);
}

struct node *insert(struct node *root, int key)
{
    // inserting the node into the tree
    if (root == NULL)
        return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);

    if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;

    // re-balancing the tree
    // since we are doing recurssions, we have a track of all the nodes visited till the target node
    // so everytime a 'return' occurs, we are going one node back in the path we had traversed

    root->height = height(root);

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->data)
        return rightRotate(root);

    if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key > root->right->data)
        return leftRotate(root);

    if (balance < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct node *root = NULL;

    /* Constructing tree given in the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be
              30
             /  \
           20   40
          /  \     \
         10  25    50
    */

    printf("Preorder traversal of the constructed AVL"
           " tree is \n");
    preOrder(root);

    return 0;
}