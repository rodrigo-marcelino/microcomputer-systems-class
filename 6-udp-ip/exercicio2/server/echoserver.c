#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>

#include "../include/defs.h"
#include "echoserver.h"

void echo(int socket_handle) {
    char buff[MAX];
    ssize_t comm_len;

    while(true) {
        memset(&buff, 0, sizeof(buff));

        // Recebe a mensagem
        comm_len = recv(socket_handle, buff, sizeof(buff), 0);
        if (comm_len < 0) {
            fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
            break;
        } else if (comm_len == 0) {
            printf("Client disconnected.\n");
            break;
        }

        printf("Received: %s\n", buff);

        
        if (strncmp("exit", buff, 4) == 0) {
            printf("Closing connection...\n");
            break;
        }

        // Mandando a resposta
        if (send(socket_handle, buff, strlen(buff) + 1, 0) < 0) {
            fprintf(stderr, "Error sending data: %s\n", strerror(errno));
            break;
        }
    }
}