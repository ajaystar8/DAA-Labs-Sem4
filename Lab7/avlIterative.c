#include <stdio.h>
#include <stdlib.h>

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

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void insertAVL(struct node **root)
{
    // pushing the nodes coming in the path into the stack
    // top of the stack will contain the ancestral node of the newly inserted node
    struct node *nodeStack[10];
    int top = -1;

    // inserting the node into the tree
    int data, n;

    printf("Enter the value of the root node: ");
    scanf("%d", &data);

    *root = newNode(data);

    printf("Enter the number of elements you want to enter: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the %dth element: ", i + 1);
        scanf("%d", &data);

        struct node *ptr = *root;
        top = -1;

        while (1)
        {
            if (data < ptr->data)
            {
                nodeStack[++top] = ptr;
                if (ptr->left == NULL)
                {
                    ptr->left = newNode(data);
                    break;
                }
                else
                {
                    ptr = ptr->left;
                }
            }
            else if (data > ptr->data)
            {
                nodeStack[++top] = ptr;
                if (ptr->right == NULL)
                {
                    ptr->right = newNode(data);
                    break;
                }
                else
                {
                    ptr = ptr->right;
                }
            }
        }
        // re-balancing the tree
        struct node *n;

        while (top != -1)
        {
            n = nodeStack[top--];

            // after rotation, the new node will get attached to the 'prev' node
            // if there is no prev, the new node becomes the root
            struct node *prev = (top == -1) ? NULL : nodeStack[top];

            n->height = height(n);

            int balance = getBalance(n);

            if (balance > 1 && data < n->left->data)
                n = rightRotate(n);

            if (balance > 1 && data > n->left->data)
            {
                n->left = leftRotate(n->left);
                n = rightRotate(n);
            }

            if (balance < -1 && data > n->right->data)
            {
                n = leftRotate(n);
            }

            if (balance < -1 && data < n->right->data)
            {
                n->right = rightRotate(n->right);
                n = leftRotate(n);
            }
            if (prev)
            {
                if (prev->data > n->data)
                    prev->left = n;
                else
                    prev->right = n;
            }
        }
        *root = n;
    }
}

int main()
{
    struct node *root = NULL;

    insertAVL(&root);

    printf("Preorder traversal of the constructed AVL tree is: \n");
    preOrder(root);

    return 0;
}