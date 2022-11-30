// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // remember value of all letters added together
    int total;

    //declare temp variable
    int i = 0;

    while(word[i] != '\n')
    {
        total = total + 
        i++
    }

    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // store each word from dictionary
    char word[LENGTH + 1];

    //open dictionary
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not open dictionary!\n");
        return false;
    }

    //iterate through each word in dictionary until end of file
    while (fscanf(dict, "%s", word) != EOF)
    {
        //make new node for each word
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            printf("Could not create space for new node!\n");
            return false;
        }

        //copy scanned word into new node
        strcpy(newNode->word, word);

        //save hash of word
        int index = hash(word);

        //leave next address blank until hashed
        newNode->next = table[index];
        table[index] = newNode;
    }

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
