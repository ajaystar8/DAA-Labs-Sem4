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
    temp->left = temp->right = NULL;
    return temp;
}

int countNodes(struct node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        opcount++;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int main()
{

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(9);
    root->right->right = newNode(8);
    root->left->left->left = newNode(6);
    root->left->left->right = newNode(7);
    printf("Total nodes in the given tree is: %d\n", countNodes(root));

    printf("Opcount: %d", opcount);

    return 0;
}