#include <stdio.h>

int main()
{
    int permission;

    printf("=== File Permission System ===\n");
    printf("1. Read Only\n");
    printf("2. Read and Write\n");
    printf("3. Read, Write and Execute\n");

    printf("\nEnter Permission Level (1-3): ");
    scanf("%d", &permission);

    printf("\nPermission Status:\n");

    if(permission >= 1)
        printf("Read Access: Allowed\n");
    else
        printf("Read Access: Denied\n");

    if(permission >= 2)
        printf("Write Access: Allowed\n");
    else
        printf("Write Access: Denied\n");

    if(permission >= 3)
        printf("Execute Access: Allowed\n");
    else
        printf("Execute Access: Denied\n");

    return 0;
}
