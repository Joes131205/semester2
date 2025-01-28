#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 26

typedef struct Node
{
    char *word;
    struct Node *next;
} Node;

Node *hash_table[MAX_SIZE];

Node *createNode(char word[])
{
    Node *new_node = malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->next = NULL;
    return new_node;
}

int hashing_function(char word[])
{
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += word[i];
    }
    return sum % MAX_SIZE;
}

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

void search(char word[])
{
    int idx = hashing_function(word);
    if (hash_table[idx] != NULL && strcmp(hash_table[idx]->word, word) == 0)
    {
        printf("%s found in hash table\n", word);
        return;
    }
    else
    {
        Node *ptr = hash_table[idx];
        while (ptr->next != NULL)
        {
            if (strcmp(ptr->next->word, word) == 0)
            {
                printf("%s found in hash table\n", word);
                return;
            }
            ptr = ptr->next;
        }
    }
}

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
        while (temp->next != NULL)
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
}
