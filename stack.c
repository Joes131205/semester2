/*
Concept:
Stack is a linear data structure that follows the LIFO (Last In, First Out) principle.
Example: A stack of books inside a box.

If you want to grab a book from the box, you would grab it from the top.
If you want to put a book into the box, you will put it on the top.
And no, you can't grab a book from the bottom.

1 -> 2 -> 3 -> 4 -> 5  (Initial stack)

You grab 1 (the top book)

2 -> 3 -> 4 -> 5       (After removing the top book)

You put 10 (a new book on top)

10 -> 2 -> 3 -> 4 -> 5 (After adding a new book to the top)

This is called LIFO (Last In, First Out).

The stack can be implemented using various data structures, such as a linked list or an array.
*/

#include <stdio.h>
#include <stdlib.h>

// In this example, we are using Linked List
typedef struct Stack
{
    int value;
    struct Stack *next;
} Stack;

Stack *head = NULL;

Stack *createStack(int val)
{

    Stack *new_node = malloc(sizeof(Stack));
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
    else
    {
        Stack *deleted = head;
        head = head->next;
        free(deleted);
    }
}

void push(int val)
{
    Stack *new_node = createStack(val);
    new_node->next = head;
    head = new_node;
}

/*

Practice Problem

Suppose you have a game that stores user information such as
- Username
- Score
- Level
- Time played

You want to implement a stack to store the user information.

Create a queue to store the user information.

How would you think Stack is better than Queue?


*/