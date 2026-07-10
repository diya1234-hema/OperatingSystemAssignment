#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char content[100];

    /* Create and Write to File */
    file = fopen("sample.txt", "w");

    if (file == NULL)
    {
        printf("Error creating file.\n");
        return 1;
    }

    fprintf(file, "Hello from Operating System Assignment!\n");
    fclose(file);

    printf("File created and data written successfully.\n\n");

    /* Read File */
    file = fopen("sample.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Reading file contents:\n");

    while (fgets(content, sizeof(content), file) != NULL)
    {
        printf("%s", content);
    }

    fclose(file);

    /* Delete File */
    if (remove("sample.txt") == 0)
    {
        printf("\nFile deleted successfully.\n");
    }
    else
    {
        printf("\nError deleting file.\n");
    }

    return 0;
}
