/**
 * @file messageclient.c
 * @brief Implementação da função responsável pela comunicação do cliente via UDP.
 *
 * Este arquivo contém a lógica para envio de mensagens UDP ao servidor, 
 * medição do tempo de resposta e registro dos resultados em um arquivo.
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <unistd.h>

#include "../include/defs.h"
#include "messageclient.h"




void msgclient(int socket_handle, SockAddrIn server_address) {
    char buff[MAX];    // Buffer para armazenar a resposta recebida do servidor
    char message[MAX]; // Mensagem a ser enviada
    ssize_t comm_len;
    socklen_t recv_len = sizeof(server_address);

    FILE *fp = fopen("results.dat", "w");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }

    printf("-------------- Protocolo UDP -----------------\n");
    fprintf(fp, "time_req time_res delta_t_ms\n");

    const int total_duration = 20; // Duração total da comunicação
    const int interval_ms = 400;   // Intervalo de cada mensagem enviado pelo cliente
    int count = (total_duration * 1000) / interval_ms;

    for (int i = 0; i < count; i++) {
        snprintf(message, sizeof(message), "Rodrigo & Yuji %d", i + 1);

        // struct timespec {
        //     time_t tv_sec;  // segundos
        //     long   tv_nsec; // nanossegundos
        // };
        struct timespec time_req, time_res;  // Define o tempo de requisição e resposta
        clock_gettime(CLOCK_REALTIME, &time_req);

        // Envia a mensagem ao servidor
        comm_len = sendto(socket_handle, message, strlen(message), 0, (SockAddr*)&server_address, sizeof(server_address));

        if (comm_len < 0) {
            perror("Send failed");
            break;
        }

        memset(buff, 0, sizeof(buff));
        // Aguarda a resposta do servidor
        comm_len = recvfrom(socket_handle, buff, sizeof(buff), 0, (SockAddr*)&server_address, &recv_len);
        if (comm_len < 0) {
            perror("Receive failed");
            break;
        }

        clock_gettime(CLOCK_REALTIME, &time_res);

        // Calculo o tempo de ida e volta (Δt) em milissegundos
        long delta_sec = time_res.tv_sec - time_req.tv_sec;
        long delta_nsec = time_res.tv_nsec - time_req.tv_nsec;
        double delta_t = delta_sec * 1000.0 + delta_nsec / 1e6;

        printf("Received: %s | Δt = %.3f ms\n", buff, delta_t);

        fprintf(fp, "%ld.%09ld %ld.%09ld %.3f\n",
                time_req.tv_sec, time_req.tv_nsec,
                time_res.tv_sec, time_res.tv_nsec,
                delta_t);

        usleep(interval_ms * 1000); // Aguarda 400ms 
    }

    fclose(fp);
    printf("Results saved to results.dat\n");
}
