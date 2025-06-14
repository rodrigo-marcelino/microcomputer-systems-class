/**
 * @file messageclient.h
 * @brief Declaração da função responsável por enviar e receber mensagens do lado do cliente UDP.
 *
 * Este cabeçalho contém a declaração da função `msgclient`, que realiza a comunicação com o servidor
 * via protocolo UDP, utilizando um socket previamente criado.
 */

#ifndef MESSAGECLIENT_H_
#define MESSAGECLIENT_H_

/**
 * @brief Envia uma mensagem ao servidor e aguarda a resposta via UDP.
 *
 * @param socket_handle inteiro que identifica o socket específico para todas as operações posteriores 
 * @param server_address Estrutura contendo o endereço e a porta do servidor.
 */
void msgclient(int socket_handle, SockAddrIn server_address);

#endif
