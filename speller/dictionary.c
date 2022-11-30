// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 104;

// Hash table
node *table[N];

//size tracker

int dictSize = 0;

// function headers
void freeList(node *thisNode);

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    //get hash of word
    int index = hash(word);

    //intialize cursor to first item in linked list
    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    //return false if no value in linked list matches word
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // remember length of word
    int length = strlen(word);

    unsigned int index = toupper(word[0]) - 'A';

    if (length > 20)
    {
        index = index + 3/4 *  N;
    }
    else if (length > 10)
    {
        index = index + 2/4 * N;
    }
    else if (length > 5)
    {
        index = index + 1/4 * N;
    }
    return index;
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
            fclose(dict);
            return false;
        }

        //copy scanned word into new node
        strcpy(newNode->word, word);

        //save hash of word
        int index = hash(word);

        //integrate node into linked list
        newNode->next = table[index];
        table[index] = newNode;
        dictSize++;
    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dictSize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    //counter variable
    int i = 0;

    //iterate through buckets
    while (i < N)
    {
        freeList(table[i]);

        //go to next bucket
        i++;
    }

    return true;
}

//frees linked list
void freeList(node *thisNode)
{
    if (thisNode == NULL)
    {
        return;
    }

    freeList(thisNode->next);
    free(thisNode);
}