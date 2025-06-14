/**
 * @file defs.h
 * @brief Definições e constantes comuns ao cliente e servidor UDP.
 *
 * Este cabeçalho contém definições, macros, estruturas e constantes que são
 * utilizadas por ambos os lados da comunicação (cliente e servidor), promovendo
 * reutilização e padronização do código.
 * 
 */
#ifndef _DEFS_H_
#define _DEFS_H_

#define TRUE 1
#define FALSE 0

/**
 * @def MAX
 * @brief Tamanho máximo de buffers.
 */
#define MAX 256


/**
 * @typedef SockAddrIn
 * @brief Alias para a estrutura `struct sockaddr_in`: armazena informações
 *        de endereço IP e porta para comunicação via sockets IPv4.
 */
typedef struct sockaddr_in SockAddrIn;


/**
 * @typedef SockAddr
 * @brief Alias para a estrutura `struct sockaddr`: estrutura genérica de endereço
 *        em chamadas de funções com sockets.
 */
typedef struct sockaddr SockAddr;

#endif