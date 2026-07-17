#include <stdio.h>
#include <string.h>

int main()
{
    char message[100];
    int i;

    printf("Enter Message: ");
    fgets(message, sizeof(message), stdin);

    printf("\nEncrypted Message: ");

    for(i = 0; message[i] != '\0'; i++)
    {
        message[i] = message[i] + 3;
        printf("%c", message[i]);
    }

    printf("\n");

    printf("\nDecrypted Message: ");

    for(i = 0; message[i] != '\0'; i++)
    {
        message[i] = message[i] - 3;
        printf("%c", message[i]);
    }

    printf("\n");

    return 0;
}
