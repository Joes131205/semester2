/*
Concept:
Queue is a linear data structure that follows the FIFO (First In, First Out) principle.
Example: People lining up for an amusement park ride.

1 -> 2 -> 3 -> 4 -> 5  (Initial queue)

1 -> 2 -> 3 -> 4       (After removing the first element)

0 -> 1 -> 2 -> 3 -> 4  (After adding a new element to the end)

0 -> 1 -> 2 -> 3       (After removing the first element again)

This is called FIFO (First In, First Out).

The queue can be implemented using various data structures, such as a linked list or an array.
*/

#include <stdio.h>
#include <stdlib.h>

// In this example, we are using Linked List
typedef struct Queue
{
    int value;
    struct Queue *next;
} Queue;

Queue *head = NULL;
Queue *tail = NULL;

Queue *createQueue(int val)
{

    Queue *new_node = malloc(sizeof(Queue));
    new_node->value = val;
    new_node->next = NULL;
    return new_node;
}

void pop()
{
    if (head == NULL)
    {
        return;
    }

    Queue *deleted = head;
    head = head->next;
    if (head == NULL)
    {
        tail = NULL;
    }
    free(deleted);
}

void push(int val)
{
    Queue *new_node = createQueue(val);
    if (tail == NULL)
    {
        head = tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
}

/*

Practice Problem

Suppose you have a game that stores user information such as
- Username
- Score
- Level
- Time played

You want to implement a queue to store the user information.

Create a queue to store the user information.

How would you think Queue is better than Stack?


*/