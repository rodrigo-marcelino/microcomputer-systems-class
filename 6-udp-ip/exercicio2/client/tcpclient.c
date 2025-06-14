#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "../include/defs.h"
#include "messageclient.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s SERVER_IP SERVER_PORT\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int client_socket;
    SockAddrIn server_address;
    char *server_ip = argv[1];
    unsigned int port = 6667;

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Config do endereço do server
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    
    // Coverte o endereço de IP para binário
    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address/Address not supported\n");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Conexão com o server
    if (connect(client_socket, (SockAddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Connection failed: %s\n", strerror(errno));
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server at %s:%d\n", server_ip, port);

    // "Handler" para a comunicação
    msgclient(client_socket, server_address);

    // Fecha o socket
    close(client_socket);
    return 0;
}