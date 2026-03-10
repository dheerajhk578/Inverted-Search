#include "inverted_search.h"

/* Hash Function */
int hash_function(char *word)
{
    if (isalpha(word[0]))
        return tolower(word[0]) - 'a';
    else
        return 26;   // Special index
}

/* Insert word into hash table */
int insert_word(Hash *arr, char *word, char *filename)
{
    int index = hash_function(word);
    Wnode *temp = arr[index].link;

    /* Check if word already exists */
    while (temp)
    {
        if (strcmp(temp->word, word) == 0)
        {
            Fnode *fptr = temp->file_link;

            /* Check if file already exists */
            while (fptr)
            {
                if (strcmp(fptr->file_name, filename) == 0)
                {
                    fptr->word_count++;
                    return SUCCESS;
                }
                fptr = fptr->link;
            }

            /* File not found → create new file node */
            Fnode *new_f = malloc(sizeof(Fnode));
            if (!new_f)
                return FAILURE;

            strcpy(new_f->file_name, filename);
            new_f->word_count = 1;
            new_f->link = temp->file_link;

            temp->file_link = new_f;
            temp->file_count++;

            return SUCCESS;
        }

        temp = temp->link;
    }

    /* Word not found → create new word node */
    Wnode *new_w = malloc(sizeof(Wnode));
    if (!new_w)
        return FAILURE;

    strcpy(new_w->word, word);
    new_w->file_count = 1;
    new_w->link = arr[index].link;
    arr[index].link = new_w;

    /* Create file node */
    Fnode *new_f = malloc(sizeof(Fnode));
    if (!new_f)
        return FAILURE;

    strcpy(new_f->file_name, filename);
    new_f->word_count = 1;
    new_f->link = NULL;

    new_w->file_link = new_f;

    return SUCCESS;
}

/* Create database */
int create_database(Hash *arr, int argc, char *argv[])
{
    FILE *fp;
    char word[50];

    for (int i = 1; i < argc; i++)
    {
        fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("ERROR: Unable to open file %s\n", argv[i]);
            continue;
        }

        while (fscanf(fp, "%49s", word) != EOF)
        {
            insert_word(arr, word, argv[i]);
        }

        fclose(fp);
    }

    printf("Database created successfully\n");
    return SUCCESS;
}