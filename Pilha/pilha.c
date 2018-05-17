/*
 * pilha.c
 * Implementação da TAD Pilha - pilha com vetor.
 */
#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

#define N 50 /* constante com o número máximo de elementos */

/* define a struct TAD pilha */
struct _pilha {
	int n;           
	void* dados[N]; //vetor de N posições do tipo void* (armazena um ponteiro de qualquer tipo)  
};

/* cria uma pilha vazia, sendo:
 * - alocar memória para a pilha (chamar malloc)
 * - atribuir o valor incial de elmentos da pilha (n = 0)
 * - retorna a pilha criada
 */
Pilha* pilha_cria (void)
{
	Pilha *pilha = malloc(sizeof(Pilha)); 
	return pilha;
}

/* retorna se a pilha esta vazia (true), ou false caso contrario */
bool pilha_vazia( Pilha* p )
{
	return (p->n <= 0);
}

/* insere um elemento na pilha, sendo:
 * - verificar se a quantidade de elementos da pilha (p->n) é menor que o número máximo de elementos (N)
 * - próxima posição livre = p->n
 * - após atribuir o dado ao vetor, incrementa p->n 
 */
void pilha_empilha( Pilha* p, void* dado )
{
	
	if(p->dados[p->n]<p->n){
		p->dados[p->n] = dado;		
	}
	p->n++;
	/* TODO implementar aqui a inserção */
}

/* retira o elemento do topo da pilha, sendo:
 * - verificar se a pilha está vazia (chamar função pilha_vazia)
 * - topo da pilha = p->n-1
 * - após armazenar o dado, é preciso decrementar p->n antes de retorná-lo
 */
void* pilha_desempilha( Pilha* p ) 
{
	/* TODO implementar aqui a remoção */
	return NULL; //Deve retornar o elemento removido
}

/* remove todos os elementos */
void pilha_destroi( Pilha* p )
{
	free(p);
}

/* imprime os elementos da pilha através da função recebida como parâmetro */
void pilha_imprime( Pilha* p, void (*imprime)(void*) )
{
	if(pilha_vazia(p)) {
		printf("ERRO! Não é possível imprimir. Pilha vazia.\n");
		return;
	}
	
	int i;
	for(i=(p->n-1); i>=0; i--) {
		imprime( p->dados[i] );
		printf("\n");
	}
}