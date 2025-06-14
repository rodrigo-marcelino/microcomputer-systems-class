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
    char buff[MAX];
    char message[MAX];
    ssize_t comm_len;
    socklen_t recv_len = sizeof(server_address);

    FILE *fp = fopen("results.dat", "w");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }

    printf("-------------- Protocolo TCP -----------------\n");
    fprintf(fp, "time_req time_res delta_t_ms\n");

    const int total_duration = 20; 
    const int interval_ms = 400;  
    int count = (total_duration * 1000) / interval_ms;

    for (int i = 0; i < count; i++) {
        snprintf(message, sizeof(message), "Rodrigo & Yuji %d", i + 1);

        struct timespec time_req, time_res;
        clock_gettime(CLOCK_REALTIME, &time_req);

        comm_len = sendto(socket_handle, message, strlen(message), 0, (SockAddr*)&server_address, sizeof(server_address));

        if (comm_len < 0) {
            perror("Send failed");
            break;
        }

        memset(buff, 0, sizeof(buff));
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

        usleep(interval_ms * 1000);
    }

    fclose(fp);
    printf("Results saved to results.dat\n");
}
