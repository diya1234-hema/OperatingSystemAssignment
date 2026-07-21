#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

void *handle_client(void *arg)
{
    int client_socket = *(int *)arg;

    char buffer[1024] = {0};
    char *message = "Authentication Successful";

    int bytes = read(client_socket, buffer, sizeof(buffer));

    if(bytes <= 0)
    {
        printf("Error receiving data\n");
        close(client_socket);
        return NULL;
    }

    if(strlen(buffer) == 0)
    {
        char *error = "Invalid Empty Message";
        send(client_socket, error, strlen(error), 0);
        close(client_socket);
        return NULL;
    }

    if(strcmp(buffer, "admin:os123") == 0)
    {
        printf("Valid user connected\n");
        send(client_socket, message, strlen(message), 0);
    }
    else
    {
        char *error = "Authentication Failed";
        send(client_socket, error, strlen(error), 0);
    }

    printf("Client says: %s\n", buffer);

    close(client_socket);

    return NULL;
}

int main()
{
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(server_fd == -1)
    {
        printf("Socket creation failed\n");
        return 1;
    }

    printf("Socket created successfully\n");

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("Bind failed\n");
        return 1;
    }

    printf("Bind successful\n");

    if(listen(server_fd, 5) < 0)
    {
        printf("Listen failed\n");
        return 1;
    }

    printf("Server listening on port %d...\n", PORT);

    while(1)
    {
        client_socket = accept(
            server_fd,
            (struct sockaddr *)&address,
            (socklen_t *)&addrlen
        );

        if(client_socket < 0)
        {
            printf("Accept failed\n");
            continue;
        }

        printf("Client connected\n");

        pthread_t thread_id;

        pthread_create(
            &thread_id,
            NULL,
            handle_client,
            &client_socket
        );

        pthread_detach(thread_id);
    }

    close(server_fd);

    return 0;
}

