#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "../include/defs.h"
#include "echoserver.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./server SERVER_PORT.\n");
        exit(EXIT_FAILURE);
    }

    int server_socket;
    int connection_socket;
    socklen_t conn_length;
    SockAddrIn server_address;
    SockAddrIn connection_address;
    unsigned long int port = strtoul(argv[1], NULL, 0);

    // Cria o socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        fprintf(stderr, "Failed to create socket.\n");
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } else {
        fprintf(stdout, "Socket successfully created.\n");
    }

    // Config do endereço do server
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);

    // Vincular o socket ao endereço
    int bind_result = bind(server_socket, (SockAddr *)&server_address, sizeof(server_address)) ;
    
    if ( bind_result < 0) {
        fprintf(stderr, "Failed to bind socket.\n");
        fprintf(stderr, "Error: %s\n", strerror(errno));
        close(server_socket);
        exit(EXIT_FAILURE);
    } else {
        fprintf ( stdout , "Socket successfully bound .\n");
    }

    // Server começa a 'escutar' requisições
    if (listen(server_socket, 2) < 0) {
        fprintf(stderr, "Failed to listen.\n");
        close(server_socket);
        exit(EXIT_FAILURE);
    } else {
        printf("Server listening on port %lu...\n", port);
    }

    // Aceitando a conexão
    conn_length = sizeof(connection_address);
    connection_socket = accept(server_socket, (SockAddr *)&connection_address, &conn_length);
    if (connection_socket < 0) {
        fprintf(stderr, "Failed to accept connection.\n");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Client connected!\n");

    // 'Handler' para a comunicação
    echo(connection_socket);

    close(connection_socket);
    close(server_socket);
    return 0;
}