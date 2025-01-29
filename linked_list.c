/*
Concept:
Linked List is a dynamic data structure in which the elements can be added to
or deleted at will

Example:

[10, 35, 26] (ARRAY)
10 -> 35 -> 26 -> NULL (LINKED LIST)

Allows insertion and deletion of any element at any location
Useful when the number of elements are unpredictable, unlike arrays
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

// Create a node
Node *createNode(int val)
{

    Node *new_node = malloc(sizeof(Node));
    new_node->value = val;
    new_node->next = NULL;
    return new_node;
}

// Push value to head
// Example
// 10 -> 20 -> 30
// pushHead(0)
// 0 -> 10 -> 20 -> 30
void pushHead(int val)
{
    Node *new_node = createNode(val);

    // If the head is null, then the list is empty
    // Hence, the new node is both the head and the tail
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    // Otherwise, the new node is the head
    else
    {
        // The new node points to the current head
        new_node->next = head;

        // The new node is now the head
        head = new_node;
    }
}

// Push value to tail
// Example
// 10 -> 20 -> 30
// pushTail(40)
// 10 -> 20 -> 30 -> 40
void pushTail(int val)
{
    Node *new_node = createNode(val);

    // If the head is null, then the list is empty
    // Hence, the new node is both the head and the tail
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    // Otherwise, the new node is the tail
    else
    {
        // The current tail points to the new node
        tail->next = new_node;

        // The new node is now the tail
        tail = new_node;
    }
}

// Push value to mid
// Example
// 10 -> 20 -> 30
// pushMid(40)
// 10 -> 20 -> 30 -> 40

// 10 -> 20 -> 40
// pushMid(30)
// 10 -> 20 -> 30 -> 40

void pushMid(int val)
{
    Node *new_node = createNode(val);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    // If the value of new node is less than value of the head,
    // we have to push head, since we want it to be ordered,
    // and vice versa
    else if (new_node->value < head->value)
    {
        pushHead(val);
    }
    else if (new_node->value > head->value)
    {
        pushTail(val);
    }
    // Otherwise, traverse the linked list to find the appropriate position
    // where the new node's value is greater than the current node's value
    // but less than or equal to the next node's value.
    else
    {
        Node *ptr = head;
        while (ptr->next != NULL && ptr->next->value < new_node->value)
        {
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
}

// Delete a head value
// Example
// 10 -> 20 -> 30
// popHead()
// 20 -> 30

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
        Node *deleted = head;
        head = head->next;
        deleted->next = NULL;
        free(deleted);
        deleted = NULL;
        return;
    }
}

void popTail()
{
    if (tail == NULL)
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

        Node *ptr = head;
        while (ptr->next != tail)
        {
            ptr = ptr->next;
        }
        tail = ptr;
        tail->next = NULL;

        free(deleted);
        deleted = NULL;
        return;
    }
}

void popMid(int val)
{
    if (head == NULL)
    {
        return;
    }
    else if (head == tail && head->value == val)
    {
        free(head);
        head = NULL;
        return;
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
        while (ptr->next != NULL && ptr->next->value != val)
        {
            ptr = ptr->next;
        }
        if (ptr->next == NULL)
        {
            return;
        }
        Node *deleted = ptr->next;
        ptr->next = deleted->next;
        if (deleted == tail)
        {
            tail = ptr;
        }
        free(deleted);
    }
}

void printAll()
{
    Node *ptr = head;
    while (ptr)
    {
        printf("[%d] -> ", ptr->value);
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

Suppose you are given a data that
needed to be put to program,
the size of the data is unknown,

How would you approach it?

Data Outline:
struct Data {
    char name[100];
    int age;
    char address[100];
    char email[100];
    char phone[100];
};


The linked list approach can be inefficient
think of a better approach!

Sort your linked list in ascending order based
on age!

*/
