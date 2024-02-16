#ifndef NETWORK_H
#define NETWORK_H

int setup_server(int port);
int accept_client(int server_socket);
int read_from_client(int client_socket, char *buffer, int buffer_size);
int send_to_client(int client_socket, const char *message);

#endif // NETWORK_H
