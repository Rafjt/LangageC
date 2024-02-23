#ifndef NETWORK_H
#define NETWORK_H

#include <SDL2/SDL_net.h>

// Initializes the SDL_net library
int network_init();

// Resolves the host for a client or server
int resolve_host(IPaddress *ip, const char *host, Uint16 port);

// Opens a TCP socket for communication
TCPsocket open_tcp_socket(IPaddress *ip);

// Closes a TCP socket
void close_tcp_socket(TCPsocket socket);

// Displays the IP address in human-readable form
void display_ip(IPaddress *ip);

// Sends data over a TCP socket
int tcp_send(TCPsocket socket, const void *data, int len);

// Receives data over a TCP socket
int tcp_recv(TCPsocket socket, void *data, int maxlen);

#endif // NETWORK_H
