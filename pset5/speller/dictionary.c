// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

int count=0;

// Hash table
node *table[27];

// Returns true if word is in dictionary, else false
bool check(const char* word)
{
    // TODO
    node* checker = malloc(sizeof(node));
    
    int bucket = hash(word);
    
    checker = table[bucket];

    while (checker != NULL){
        if(strcasecmp(checker->word, word) == 0){
            return true;
        }
        checker = checker->next;
    }
    //free(checker->word);
    //free(checker->next);
    free(checker);
    return false;
}

// Hashes word to a number
unsigned int hash(const char* word)
{
    // TODO
    int index = 0;

    for (int i = 0; word[i] != '\0'; i++){
        index += tolower(word[i]);
    }
    return index % 27;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE* dico = fopen(dictionary, "r");
    if (dico == NULL){
        return false;
    }
    
    char yeet[LENGTH + 1];
    
    while (fscanf(dico, "%s\n", yeet) != EOF){
        node* ne = malloc(sizeof(node));
        //ne->word = (malloc(sizeof(yeet) - 2));
        strcpy(ne->word, yeet);
        int hashed = hash(yeet);

        if(table[hashed] == NULL){
            table[hashed] = ne;
            ne->next = NULL;
        }

        else{
            ne->next = table[hashed];
            table[hashed] = ne;
        }
        count++;
    }
    //free(ne->word);
    //free(ne->next);
    fclose(dico);
    
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    bool result = false;
    for (int i = 0; i < 27; i++){
        node *cursor;
        cursor = table[i];
        
        while(cursor){
            node* tmp = cursor;
            cursor = cursor->next;
            free(tmp);
            return true;
        }
        table[i] = NULL;
        free(cursor);
    }
    return false;
}
