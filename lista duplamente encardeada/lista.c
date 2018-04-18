/*
 * lista.c
 * Implementação da TAD Lista - lista duplamente encadeada.
*/
#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

/* define a struct TAD lista */
struct lista {
	Ponto* dado;        /* ponteiro para o dado da lista Ponto */
	struct lista *prox; /* ponteiro para o proximo elemento */
	struct lista *ant;  /* ponteiro para o elemento anterior */
};

/* cria lista vazia */
Lista* lista_cria(void)
{
	return NULL;
}

/* retorna se a lista esta vazia (true), ou false caso contrario */
bool lista_vazia( Lista* l )
{
	return (l == NULL);
}

/* insere no comeco da lista, retorna a lista atualizada */
Lista* lista_insere( Lista* l, Ponto* ponto )
{
	Lista *L= (Lista*)malloc(sizeof(Lista));
	L->dado = ponto;
	L->ant = NULL;
	L->prox = l;
	if(l!=NULL)
		l->ant = L;
	return L;	
}

/* busca um elemento na lista e retorna-o caso ele seja encontrado */
Lista* lista_busca( Lista* l, Ponto* p ) {
	Lista* elem = l;
	while(elem != NULL) {
		if(compara_ponto(elem->dado, p))
			return elem;
		elem = elem->prox;
	}
	
	return NULL;
}

/* imprime todos os elementos da lista */
void lista_imprime( Lista* l ) {
	Lista *tmp, *ultimo;

	if(lista_vazia(l))
		printf("%s: LISTA VAZIA!\n", __FUNCTION__);
	else {
		printf("(%s) EM ORDEM: ", __FUNCTION__);
		tmp = l;
		ultimo = l;
		while(lista_vazia(tmp) == false){
			imprime_ponto(tmp->dado);
			ultimo = tmp;
			tmp = tmp->prox;
		}
		printf("\n\n");
		printf("(%s) ORDEM INVERSA: ", __FUNCTION__);
		while(lista_vazia(ultimo) == false){
			imprime_ponto(ultimo->dado);
			ultimo = ultimo->ant;
		}
		printf("\n");
	}
}

/* remove da lista o elemento que contem o Ponto. Se lista ficar vazia, retorna NULL.
   Se não encontrou, retorna a lista 'l'.
   Senao, o elemento removido deve ser liberrado com free.
   ATENÇÃO: não libera memória dos dados.
*/
Lista* lista_remove( Lista* l, Ponto* p ) {
	Lista *L = lista_busca(l,p);
	
	if(L!=NULL){
		if(L->ant == NULL){
			if(l->prox != NULL){
				l->prox->ant = NULL; 
				l = l->prox;
			}
		}
		else if(L->ant != NULL && L->prox != NULL){
			l->prox = L->prox;
			l->ant = L->ant;
		}
		else if(L->prox == NULL){
			l->prox = NULL;
		}  
	}
	return l;
}

/* Remove todos os elementos */
void lista_destroi( Lista* l )
{
	Lista* elem = l;
	while( lista_vazia(elem) == false ){
		Lista* t = elem->prox;
		free(elem);
		elem = t;
	}
}