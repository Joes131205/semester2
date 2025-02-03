#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *root = NULL;

TreeNode *createNode(int val)
{
    TreeNode *newNode = malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insert(int val)
{
    TreeNode *newNode = createNode(val);
    if (!root)
    {
        root = newNode;
        return;
    }

    TreeNode *parent = NULL;
    TreeNode *curr = root;

    while (curr)
    {
        parent = curr;
        if (val < curr->val)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    if (val < parent->val)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
}

int search(int val)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->val == val)
    {
        return 1;
    }
    else
    {
        TreeNode *ptr = root;
        while (ptr)
        {
            if (val == ptr->val)
            {
                return 1;
            }

            if (val < ptr->left->val)
            {
                ptr = ptr->left;
            }
            else
            {
                ptr = ptr->right;
            }
        }
    }
    return 0;
}

void delete(int val)
{
    if (!root)
    {
        return;
    }
    else if (root->val == val)
    {
        free(root);
        root = NULL;
    }
    else
    {
        TreeNode *parent = NULL;
        TreeNode *curr = parent;
    }
}

void printAll(TreeNode *root)
{
    if (!root)
        return;

    printf("%d\n", root->val);

    printAll(root->left);
    printAll(root->right);
}

int main()
{

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    printAll(root);
}