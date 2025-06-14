/**
 * @file echoserver.h
 * @brief Define a função que recebe mensagens UDP de clientes e as reenvia (echo) para o remetente.
 * 
 */

#ifndef _ECHOSERVER_H_
#define _ECHOSERVER_H_

/**
 * @brief Função que executa o servidor UDP retornando mensagens recebidas.
 *
 * Esta função fica em loop (server listening...) recebendo mensagens dos clientes e
 * enviando-as de volta.
 *
 * @param socket_handle inteiro que identifica o socket
 */
void echo(int socket_handle);

#endif
