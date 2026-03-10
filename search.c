#include "inverted_search.h"

/* Search Word */
int search_word(Hash *arr, char *word)
{
    int index = hash_function(word);
    Wnode *temp = arr[index].link;

    while (temp)
    {
        if (strcmp(temp->word, word) == 0)
        {
            printf("\nWord '%s' found in %d file(s)\n",
                    word, temp->file_count);

            Fnode *fptr = temp->file_link;

            while (fptr)
            {
                printf("File: %-15s Count: %d\n",
                        fptr->file_name,
                        fptr->word_count);
                fptr = fptr->link;
            }

            return SUCCESS;
        }

        temp = temp->link;
    }

    printf("Word '%s' not found\n", word);
    return FAILURE;
}


/* Display Entire Database */
int display_database(Hash *arr)
{
    int empty = 1;

    for (int i = 0; i < HASH_SIZE; i++)
    {
        if (arr[i].link != NULL)
        {
            empty = 0;
            printf("\nIndex [%d]:\n", i);

            Wnode *wptr = arr[i].link;

            while (wptr)
            {
                printf("  Word: %-15s File Count: %d\n",
                        wptr->word,
                        wptr->file_count);

                Fnode *fptr = wptr->file_link;

                while (fptr)
                {
                    printf("       File: %-15s Count: %d\n",
                            fptr->file_name,
                            fptr->word_count);
                    fptr = fptr->link;
                }

                wptr = wptr->link;
            }
        }
    }

    if (empty)
    {
        printf("Database is empty\n");
        return FAILURE;
    }

    return SUCCESS;
}