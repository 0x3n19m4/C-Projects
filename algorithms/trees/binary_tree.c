#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* root, int number)
{
    if (root == NULL)
    {
        struct node* new_node = malloc(sizeof(struct node));
        new_node -> number = number;
        new_node -> left = NULL;
        new_node -> right = NULL;
        return new_node;    
    }

    if (number < root -> number)
        root -> left = insert(root -> left, number);
    else
        root -> right = insert(root -> right, number);

    return root;
};

struct node* search(struct node* root, int number)
{
    if (root == NULL || root -> number == number)
        return root;

    if (number < root -> number)
        return search(root -> left, number);
    else
        return search(root -> right, number);
};

void inOrder(struct node* root)
{
    if (root != NULL)
    {
        inOrder(root -> left);
        printf("%d ", root -> number);
        inOrder(root -> right);
    }
}

int main()
{
    struct node* root = NULL;

    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 10);
    root = insert(root, 2);
    root = insert(root, 9);
    root = insert(root, 7);
    root = insert(root, 14);

    inOrder(root);

    struct node* found = search(root, 10);

    if (found != NULL)
        printf("\nFound: %d\n", found -> number);
    else
        printf("\nNot Found\n");
   
    return 0;
}
