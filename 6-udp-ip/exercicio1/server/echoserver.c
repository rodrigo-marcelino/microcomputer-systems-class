/**
 * @file echoserver.c
 * @brief Implementação do servidor UDP que retorna mensagens recebidas.
 *
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>

#include "../include/defs.h"
#include "echoserver.h"

void echo(int socket_handle) {
    char buff[MAX];
    socklen_t len;
    ssize_t comm_len;
    SockAddrIn client_address;

    len = sizeof(client_address);

    while(TRUE) {
        // Limpando o buffer
        memset(& buff, 0, sizeof( buff ));
        memset(& client_address, 0, sizeof( client_address ));
        // Lê a mensagem do cliente e copia para o buffer
        comm_len = recvfrom(socket_handle, buff, sizeof(buff), 0, (SockAddr*)&client_address, &len);
        if (comm_len < 0) {
            fprintf ( stderr , "An error occurred while receiving data .\n") ;
            fprintf ( stderr , " Error : %s\n", strerror ( errno ));
            break;
        }

        fprintf(stdout, "[Client] %s\n", buff);

        if (strncmp("exit", buff, 4) == 0) {
            fprintf(stdout , "Server execution finished.");
            break;
        }

        // Envia a mensagem de volta para o cliente (echo)
        comm_len = sendto(socket_handle, (char *) & buff, sizeof(buff), 0, (SockAddr *) & client_address, len);
        if (comm_len < 0) {
            fprintf(stderr , "An error occurred while sending data.\n");
            fprintf(stderr, "Error : %s\n", strerror( errno));
            break;
        }
    }
}