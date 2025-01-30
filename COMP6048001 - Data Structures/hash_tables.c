/*
Concept:
Hash Table is a data structure that maps keys to values for highly efficient lookup.
It uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.

Example:
Consider a hash table with a size of 26 (for simplicity, let's assume it only stores lowercase English letters).

The hash function computes the index based on the sum of the ASCII values of the characters in the word, modulo the size of the hash table.

For example:
"apple" -> sum of ASCII values = 97 + 112 + 112 + 108 + 101 = 530
530 % 26 = 10 (index)

The hash table can handle collisions using linked lists (chaining).

The hash table can be implemented using an array of linked lists.

Operations:
- Insert: Add a new word to the hash table.
- Search: Find a word in the hash table.
- Delete: Remove a word from the hash table.


Example Hash Table:

Index  | Linked List
---------------------
0      | NULL
1      | NULL
2      | NULL
3      | NULL
4      | NULL
5      | NULL
6      | NULL
7      | NULL
8      | NULL
9      | NULL
10     | apple -> NULL
11     | NULL
12     | NULL
13     | pineapple -> pear -> NULL
14     | NULL
15     | NULL
16     | NULL
17     | NULL
18     | NULL
19     | NULL
20     | NULL
21     | NULL
22     | NULL
23     | NULL
24     | NULL
25     | NULL

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The size of hash table can be vary
#define MAX_SIZE 26

// There are various way to implement this
// Like using linked list, array, etc.
// For example sake, we use linked list

typedef struct Node
{
    char *word;
    struct Node *next;
} Node;

Node *hash_table[MAX_SIZE];

Node *createNode(char word[])
{
    Node *new_node = malloc(sizeof(Node));
    new_node->word = malloc(strlen(word) + 1);
    strcpy(new_node->word, word);
    new_node->next = NULL;
    return new_node;
}

// Hashing function
int hashing_function(char word[])
{
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += word[i];
    }
    return sum % MAX_SIZE;
}

// Insert a value to the hash table
void insert(Node *node)
{
    int idx = hashing_function(node->word);
    if (hash_table[idx] == NULL)
    {
        hash_table[idx] = node;
    }
    else
    {
        Node *ptr = hash_table[idx];
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = node;
    }
}

// Search a value in the hash table
void search(char word[])
{
    int idx = hashing_function(word);
    Node *ptr = hash_table[idx];
    while (ptr != NULL)
    {
        if (strcmp(ptr->word, word) == 0)
        {
            printf("%s found in hash table\n", word);
            return;
        }
        ptr = ptr->next;
    }
    printf("%s not found in hash table\n", word);
}

// Delete a value from the hash table
void delete(char word[])
{
    int idx = hashing_function(word);
    if (hash_table[idx] != NULL && strcmp(hash_table[idx]->word, word) == 0)
    {
        Node *temp = hash_table[idx];
        hash_table[idx] = temp->next;
        free(temp);
        return;
    }
    else
    {
        Node *temp = hash_table[idx];
        while (temp != NULL && temp->next != NULL)
        {
            if (strcmp(temp->next->word, word) == 0)
            {
                Node *deleted = temp->next;
                temp->next = temp->next->next;
                free(deleted);
                return;
            }
            temp = temp->next;
        }
    }
    printf("%s not found in hash table\n", word);
}

/*

Practice Problem

Suppose you have a game that stores user information such as
username, email, and score. Implement a database to hold such data

Given your implementation in linked_list.c, how would you improve the database?

*/