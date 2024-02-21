#include "network.h"
#include <stdio.h>
#include <stdlib.h>

int network_init() {
    if (SDLNet_Init() < 0) {
        fprintf(stderr, "Error in SDLNet_Init: %s\n", SDLNet_GetError());
        return -1; // Return an error code
    }
    return 0; // Success
}

int resolve_host(IPaddress *ip, const char *host, Uint16 port) {
    if (SDLNet_ResolveHost(ip, host, port) != 0) {
        fprintf(stderr, "Error in SDLNet_ResolveHost: %s\n", SDLNet_GetError());
        return -1; // Return an error code
    }
    return 0; // Success
}

TCPsocket open_tcp_socket(IPaddress *ip) {
    TCPsocket socket = SDLNet_TCP_Open(ip);
    if (!socket) {
        fprintf(stderr, "Error in SDLNet_TCP_Open: %s\n", SDLNet_GetError());
        exit(EXIT_FAILURE); // Exit if we can't open a socket
    }
    return socket; // Return the opened socket
}

void close_tcp_socket(TCPsocket socket) {
    SDLNet_TCP_Close(socket);
}

void display_ip(IPaddress *ip) {
    Uint32 intip = SDL_SwapBE32(ip->host);
    printf("%d.%d.%d.%d:%u\n",
           (intip >> 24), (intip >> 16) & 0xff, (intip >> 8) & 0xff, intip & 0xff,
           ip->port);
}

int tcp_send(TCPsocket socket, const void *data, int len) {
    int result = SDLNet_TCP_Send(socket, data, len);
    if (result < len) {
        fprintf(stderr, "SDLNet_TCP_Send: %s\n", SDLNet_GetError());
        return -1; // Return an error code
    }
    return result; // Return the number of bytes sent
}

int tcp_recv(TCPsocket socket, void *data, int maxlen) {
    int result = SDLNet_TCP_Recv(socket, data, maxlen);
    if (result <= 0) {
        fprintf(stderr, "SDLNet_TCP_Recv: %s\n", SDLNet_GetError());
        return -1; // Return an error code
    }
    return result; // Return the number of bytes received
}
