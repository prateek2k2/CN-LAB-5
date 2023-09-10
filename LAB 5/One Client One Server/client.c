#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];
    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error in socket creation");
        exit(1);
    }
    printf("Client socket created.\n");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error in connection");
        exit(1);
    }
    printf("Connected to the server.\n");
    while (1) {
        printf("Enter a message (or 'exit' to quit): ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        send(client_socket, buffer, strlen(buffer), 0);
        if (strcmp(buffer, "exit\n") == 0) {
            printf("Client exiting...\n");
            break;
        }
        bzero(buffer, sizeof(buffer));
        recv(client_socket, buffer, sizeof(buffer), 0);
        printf("Server: %s", buffer);
    }
    close(client_socket);
    return 0;
}

