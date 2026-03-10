#include "inverted_search.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./a.out file1 file2 ...\n");
        return 0;
    }

    Hash arr[HASH_SIZE];

    /* Initialize hash table */
    for (int i = 0; i < HASH_SIZE; i++)
    {
        arr[i].index = i;
        arr[i].link = NULL;
    }

    int choice;
    char word[50];
    char file[30];

    while (1)
    {
        printf("\n----- INVERTED SEARCH MENU -----\n");
        printf("1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Search Word\n");
        printf("4. Save Database\n");
        printf("5. Update Database\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create_database(arr, argc, argv);
                break;

            case 2:
                display_database(arr);
                break;

            case 3:
                printf("Enter word to search: ");
                scanf("%s", word);
                search_word(arr, word);
                break;

            case 4:
                printf("Enter filename to save database: ");
                scanf("%s", file);
                save_database(arr, file);
                break;

            case 5:
                printf("Enter filename to update database: ");
                scanf("%s", file);
                update_database(arr, file);
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}