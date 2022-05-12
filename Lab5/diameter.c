#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int opcount = 0;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int height(struct node *root)
{
    opcount++;
    if (root == NULL)
        return 0;

    else
        return 1 + max(height(root->left), height(root->right));
}

int diameter(struct node *tree)
{
    opcount++;
    if (tree == NULL)
        return 0;

    int lheight = height(tree->left);
    int rheight = height(tree->right);

    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);

    return max((lheight + rheight + 1), max(ldiameter, rdiameter));
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Diameter of the given binary tree is %d\n", diameter(root));

    printf("Opcount: %d\n", opcount);
    return 0;
}