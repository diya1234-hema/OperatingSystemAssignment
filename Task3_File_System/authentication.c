#include <stdio.h>
#include <string.h>

int main()
{
    char username[50];
    char password[50];

    char validUsername[] = "admin";
    char validPassword[] = "os123";

    printf("=== User Authentication System ===\n");

    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    if(strcmp(username, validUsername) == 0 &&
       strcmp(password, validPassword) == 0)
    {
        printf("\nAccess Granted!\n");
    }
    else
    {
        printf("\nAccess Denied!\n");
    }

    return 0;
}
   
