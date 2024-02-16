#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "network.h"

int setup_server(int port) {
    int server_fd;
    struct sockaddr_in address;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    return server_fd;
}

int accept_client(int server_socket) {
    int new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    return new_socket;
}

int read_from_client(int client_socket, char *buffer, int buffer_size) {
    int valread = read(client_socket, buffer, buffer_size);
    if (valread < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    buffer[valread] = '\0'; // Null-terminate the string if necessary
    return valread;
}

int send_to_client(int client_socket, const char *message) {
    int sent = send(client_socket, message, strlen(message), 0);
    if (sent < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    return sent;
}
