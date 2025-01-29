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

    Node *new_node = malloc(sizeof(Node));
    new_node->value = val;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
void pushHead(int val)
{
    Node *new_node = createNode(val);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}
void pushTail(int val)
{
    Node *new_node = createNode(val);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}
void pushMid(int val)
{
    Node *new_node = createNode(val);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else if (head->value > val)
    {
        pushHead(val);
    }
    else if (head->value < val)
    {
        pushTail(val);
    }
    else
    {
        Node *ptr = head->next;
        while (ptr != NULL && ptr->value != val)
        {
            ptr = ptr->next;
        }

        // Do something with prev
        ptr->prev->next = new_node;
        new_node->prev = ptr->prev;

        // Do something with next
        ptr->prev = new_node;
        new_node->next = ptr;
    }
}

void popHead()
{
    if (head == NULL)
    {
        return;
    }
    else if (head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }
    else
    {
        Node *curr = head;
        head = head->next;
        head->prev = NULL;

        curr->next = NULL;

        free(curr);
        curr = NULL;
    }
}
void popTail()
{
    if (head == NULL)
    {
        return;
    }
    else if (head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }
    else
    {
        Node *deleted = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(deleted);
    }
}
void popMid(int val)
{
    if (head == NULL)
    {
        return;
    }
    else if (head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else if (head->value == val)
    {
        popHead();
    }
    else if (tail->value == val)
    {
        popTail();
    }
    else
    {
        Node *ptr = head;
        while (ptr != NULL && ptr->value != val)
        {
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            return;
        }

        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;

        ptr->next = NULL;
        ptr->prev = NULL;

        free(ptr);
        ptr = NULL;
    }
}

void printAll()
{
    Node *ptr = head;
    while (ptr)
    {
        printf("[%d] <-> ", ptr->value);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void freeMemory()
{
    Node *ptr = head;
    while (ptr)
    {
        Node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}

/*

Practice Problem

Same as the previous problem, but this time
use doubly linked list!

*/