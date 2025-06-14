#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "../include/defs.h"
#include "messageclient.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s SERVER_IP\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int client_socket;
    SockAddrIn server_address;
    char *server_ip = argv[1];
    unsigned long port = 6666;

    client_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(port);

    msgclient(client_socket, server_address);
    close(client_socket);
    return EXIT_SUCCESS;
}
