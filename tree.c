#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *root = NULL;

TreeNode *createNode(int val)
{
    TreeNode *new_node = malloc(sizeof(TreeNode));
    new_node->value = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(TreeNode *node, int val)
{
    if (node == NULL)
    {
        root = createNode(val);
        return;
    }
    else
    {
        if (node->value > val)
        {
            if (node->left == NULL)
            {
                node->left = createNode(val);
                return;
            }
            else
            {
                insert(node->left, val);
            }
        }
        else
        {
            if (node->right == NULL)
            {
                node->right = createNode(val);
                return;
            }
            else
            {
                insert(node->right, val);
            }
        }
    }
}

void delete(int val) {}

void preorder(TreeNode *node)
{
    if (!node)
        return;
    printf("%d ", node->value);
    preorder(node->left);
    preorder(node->right);
}

void search(TreeNode *node, int val)
{
    if (!root)
        return;

    if (node->value == val)
    {
        printf("Found\n");
        return;
    }
    else
    {
        if (node->value > val)
            search(node->left, val);
        else
            search(node->right, val);
    }
}