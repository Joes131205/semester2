#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

    int value;
    struct Node *next;
    struct Node *prev;

} Node;

Node *head = NULL;
Node *tail = NULL;

Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtPosition(int index, int value)
{
    int idx = 0;
    Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *ptr = head;
        while (idx != index && ptr != NULL)
        {
            idx++;
            ptr = ptr->next;
        }
        if (ptr->next == NULL)
        {
            return;
        }

        newNode->next = ptr;
        newNode->prev = ptr->prev;

        ptr->prev = newNode;
    }
}

void deleteAtPosition(int index)
{
}

void reverse()
{
}