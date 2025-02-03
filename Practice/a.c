#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(int value)
{
    Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(int value)
{
    Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteByValue(int value)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->value == value)
    {
        Node *temp = head;
        Node *prev = NULL;
        head = head->next;

        free(temp);

        if (head == NULL)
            tail = NULL;
    }
    else
    {
        Node *temp = head;
        Node *prev = NULL;

        while (temp != NULL && temp->value != value)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        prev->next = temp->next;

        if (temp == tail)
            tail = prev;

        free(temp);
    }
}

void reverse()
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    tail = head;
    head = prev;
}
