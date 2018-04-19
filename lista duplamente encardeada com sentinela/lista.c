/*
 * lista.c
 * Implementação das TADs Nodo e Sentinela - lista duplamente encadeada.
*/
#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

/* define a struct TAD nodo */
struct nodo {
	Ponto* dado;        /* ponteiro para o dado da lista Ponto */
	struct nodo *prox; /* ponteiro para o proximo elemento */
	struct nodo *ant;  /* ponteiro para o elemento anterior */
};

/* define a struct TAD sentinela */
struct sentinela {
	int nItens;          /* número de elementos na lista. Atualizar ao inserir e remover da lista */
	struct nodo *cabeca; /* ponteiro para o primeiro elemento da lista */
	struct nodo *cauda;  /* ponteiro para o último elemento da lista */
};

/* cria lista vazia */
Sentinela* lista_cria(void)
{
	//Método pronto - cria a lista vazia a partir da sentinela
	Sentinela *sentinela = (Sentinela*) malloc(sizeof(Sentinela));
	sentinela->nItens = 0;
	sentinela->cabeca = NULL;
	sentinela->cauda  = NULL;
	return sentinela;
}

/* retorna se a lista esta vazia (true), ou false caso contrario */
bool lista_vazia( Sentinela* l )
{
	
	return (l == NULL);
}

/* insere no comeco da lista, retornando a lista atualizada */
Sentinela* lista_insere( Sentinela* l, Ponto* ponto )
{
 Nodo *L = (Nodo*)malloc(sizeof(Nodo));
 	L->dado =ponto;
 	if(l->nItens == 0){
 		l->cauda = L;
 		l->cabeca = L;
 	}
 	else if(l->nItens>0){
 		L->prox = l->cabeca;
 		l->cabeca->ant = L;
 		l->cabeca = L; 
 	}
 	else{
 		l->cabeca = L;
 		l->cabeca->ant = NULL;
 	}
 	l->nItens++;
 	return l;
}

Nodo* lista_busca( Sentinela* l, Ponto* p ) {
Nodo* elem = l->cabeca;
	while(elem != NULL) {
		if(compara_ponto(elem->dado, p))
				return elem;
		elem = elem->prox;
	}
	
	return NULL;
}

/* imprime todos os elementos da lista em ordem - começa da cabeça da Sentinela */
void lista_imprime_ordem( Sentinela* l ) {

	Nodo *tmp;
	if(lista_vazia(l))
		printf("%s: LISTA VAZIA!\n", __FUNCTION__);
	else {
		printf("(%s) EM ORDEM: ", __FUNCTION__);
		tmp = l->cauda;
		while(tmp != NULL){
			imprime_ponto(tmp->dado);
			tmp = tmp->ant;
		}
		printf("\n\n");
	}
}

/* imprime todos os elementos da lista em ordem inversa - começa da cauda da Sentinela */
void lista_imprime_ordem_inv( Sentinela* l ) {
	Nodo *ultimo;
	ultimo = l->cabeca;
	printf("(%s) ORDEM INVERSA: ", __FUNCTION__);
		while(ultimo != NULL){
			imprime_ponto(ultimo->dado);
			ultimo = ultimo->prox;
		}
}

/* remove da lista o elemento que contem o Ponto.
   Se não encontrou, retorna 'l'. 
   Senao, o elemento removido deve ser liberrado com free.
   ATENÇÃO: não libera memória do ponto.
*/
Sentinela* lista_remove( Sentinela* l, Ponto* p ) {
	
Nodo *r = lista_busca(l,p);
	
	if(r == NULL){ //Caso não encontrado
		l->nItens--;
		return l;
	}
	else{
		if(r->ant == NULL) { //Caso for o primeiro
			if(l->cauda->prox != NULL) //Caso possua um proximo, seta seu anterior para NULL
				l->cauda->prox->ant = NULL;
			l->cauda = l->cauda->prox;

			}else if(r->prox == NULL) { //Caso for o último
				r->ant->prox = NULL;
		
			}else{ //Caso for nó do meio
				r->ant->prox = r->prox;
				r->prox->ant = r->ant;
		}
		l->cabeca = r->prox;
		l->nItens--;
	}
		free(r);
	return l;

}

/* Remove todos os elementos, liberando-os. Liberar também a sentinela.
   ATENÇÃO: não libera memória do ponto. */
void lista_destroi( Sentinela* l )
{
	Nodo* elem = l->cabeca;
	while(elem!=NULL){
		Nodo* t = elem->prox;
		free(elem);
		elem = t;
	}
	free(l);

}
