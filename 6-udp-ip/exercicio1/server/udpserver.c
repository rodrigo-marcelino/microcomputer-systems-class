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
        fprintf(stderr, "Usage: %s SERVER_PORT\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int server_socket;
    SockAddrIn server_address;
    unsigned long port = strtoul(argv[1], NULL, 0);

    // Cria socket
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    } else {
        fprintf(stdout, "Socket succssfully created.\n");
    }

    memset(&server_address, 0, sizeof(server_address));

    // Configure server IP adress and PORT
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);

    // Bind newly created socket to server IP address
    int bind_result = bind(server_socket, (SockAddr *) & server_address, sizeof(server_address));

    if (bind_result < 0) {
        fprintf ( stderr , " Failed to bind socket to address .\n");
        fprintf ( stderr , " Error : %s\n", strerror ( errno ));
        close ( server_socket );
        exit ( EXIT_FAILURE );
    }
        fprintf ( stdout , "Socket successfully bound .\n");

    // Echo function . Defined in echoserver .h
    echo(server_socket);
    // Close the socket when the server finishes its execution
    close(server_socket);
    return EXIT_SUCCESS;
}