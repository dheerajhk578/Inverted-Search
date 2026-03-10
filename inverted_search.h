#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1
#define HASH_SIZE 27   // 26 alphabets + 1 special

/* File node */
typedef struct file_node
{
    char file_name[30];
    int word_count;
    struct file_node *link;
} Fnode;

/* Word node */
typedef struct word_node
{
    char word[50];
    int file_count;
    Fnode *file_link;
    struct word_node *link;
} Wnode;

/* Hash table */
typedef struct hash_table
{
    int index;
    Wnode *link;
} Hash;

/* Function declarations */
int create_database(Hash *arr, int argc, char *argv[]);
int insert_word(Hash *arr, char *word, char *filename);
int display_database(Hash *arr);
int search_word(Hash *arr, char *word);
int save_database(Hash *arr, char *filename);
int update_database(Hash *arr, char *filename);
int hash_function(char *word);

#endif