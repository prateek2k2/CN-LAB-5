#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    char buffer[MAX_BUFFER_SIZE];
    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error in socket creation");
        exit(1);
    }
    printf("Server socket created.\n");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error in binding");
        exit(1);
    }
    printf("Binding successul.\n");
    // Listen for incoming connections
    if (listen(server_socket, 10) == 0) {
        printf("Listening...\n");
    } else {
        printf("Error in listening\n");
        exit(1);
    }
    addr_size = sizeof(new_addr);
    new_socket = accept(server_socket, (struct sockaddr*)&new_addr, &addr_size); // Accept a connection
    // Read and echo data back to the client
    while (1) {
        recv(new_socket, buffer, MAX_BUFFER_SIZE, 0);
        if (strcmp(buffer, "exit") == 0) {
            printf("Server exiting...\n");
            break;
        }
        printf("Client: %s", buffer);
        send(new_socket, buffer, strlen(buffer), 0);
        bzero(buffer, sizeof(buffer));
    }
    close(new_socket);
    close(server_socket);
    return 0;
}

