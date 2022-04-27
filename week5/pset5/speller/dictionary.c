// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

unsigned int hash(const char *word);

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // hash the word

    int hash_value = hash(word);

    // acces hash table in the hash index

    node *cursor = table[hash_value];

    // look for the word in the linked list

    while (cursor != NULL)
    {
        int found = strcasecmp(cursor -> word, word);

        if (found == 0)
        {
            return true;
            break;
        }

        cursor = cursor -> next;

    }

    return false;

}

int word_counter = 0;

// Hashes word to a number
unsigned int hash(const char *word)
{
    char lower_word[2];

    lower_word[0] = tolower(word[0]);

    lower_word[1] = tolower(word[1]);

    int hash_value = (((int)lower_word[0] - 97) + ((int)lower_word[1] - 97) + (((int)lower_word[0] - 97) * 25));

    if (hash_value < N && hash_value >= 0)
    {
        return hash_value;
    }
    else
    {
        return 0;
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    for (int i = 0; i < N; i ++)
    {
        table[i] = NULL;
    }

    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }


    char d_word[LENGTH + 1];

    while (fscanf(file, "%s", d_word) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n != NULL)
        {
            strcpy(n -> word, d_word);

            n -> next = NULL;
        }
        else
        {
            printf("Error allocating memory\n");
            return false;
            break;
        }

        int hash_value = hash(d_word);

        if (table[hash_value] == NULL)
        {
            table[hash_value] = n;
        }
        else
        {
            // insertar al principio de la linked list

            n -> next = table[hash_value];

            table[hash_value] = n;

        }

        word_counter += 1;

    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{

    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;

            cursor = cursor -> next;

            free(tmp);

        }
    }

    return true;

}
