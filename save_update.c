#include "inverted_search.h"

/* Save Database */
int save_database(Hash *arr, char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (!fp)
    {
        printf("ERROR: Unable to open file %s\n", filename);
        return FAILURE;
    }

    for (int i = 0; i < HASH_SIZE; i++)
    {
        Wnode *wptr = arr[i].link;

        while (wptr)
        {
            fprintf(fp, "#%d;%s;%d;",
                    i,
                    wptr->word,
                    wptr->file_count);

            Fnode *fptr = wptr->file_link;

            while (fptr)
            {
                fprintf(fp, "%s;%d;",
                        fptr->file_name,
                        fptr->word_count);
                fptr = fptr->link;
            }

            fprintf(fp, "#\n");

            wptr = wptr->link;
        }
    }

    fclose(fp);
    printf("Database saved successfully\n");
    return SUCCESS;
}


/* Update Database from Saved File */
int update_database(Hash *arr, char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("ERROR: Unable to open file %s\n", filename);
        return FAILURE;
    }

    int index, file_count, word_count;
    char word[50], file_name[30];

    while (fscanf(fp, "#%d;%[^;];%d;",
                  &index, word, &file_count) == 3)
    {
        for (int i = 0; i < file_count; i++)
        {
            fscanf(fp, "%[^;];%d;",
                   file_name, &word_count);

            for (int j = 0; j < word_count; j++)
            {
                insert_word(arr, word, file_name);
            }
        }

        fscanf(fp, "#\n");
    }

    fclose(fp);

    printf("Database updated successfully\n");
    return SUCCESS;
}