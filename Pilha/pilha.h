/*
 * pilha.h
 * Definição da TAD Pilha - pilha com vetor.
 */

#ifndef _PILHA_H_
#define _PILHA_H_

#include <stdbool.h>

/* define o tipo Pilha, derivado da 'struct _pilha' */
typedef struct _pilha Pilha;

/* cria uma pilha vazia, sendo:
 * - alocar memória para a pilha (chamar malloc)
 * - atribuir o valor incial de elmentos da pilha (n = 0)
 * - retorna a pilha criada
 */
Pilha* pilha_cria (void);

/* retorna se a pilha esta vazia (true), ou false caso contrario */
bool pilha_vazia( Pilha* p );

/* insere um elemento na pilha, sendo:
 * - verificar se a quantidade de elementos da pilha (p->n) é menor que o número máximo de elementos (N)
 * - próxima posição livre = p->n
 * - após atribuir o dado ao vetor, incrementa p->n 
 */
void pilha_empilha( Pilha* p, void* dado );

/* retira o elemento do topo da pilha, sendo:
 * - verificar se a pilha está vazia (chamar função pilha vazia)
 * - topo da pilha = p->n-1
 * - após armazenar o dado, é preciso decrementar p->n antes de retorná-lo
 */
void* pilha_desempilha( Pilha* p ); 

/* destroi a pilha */
void pilha_destroi( Pilha* p );

/* imprime os elementos da pilha através da função recebida como parâmetro */
void pilha_imprime( Pilha* p, void (*imprime)(void*) );

#endif