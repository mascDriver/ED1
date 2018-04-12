#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

/* define a struct TAD lista */
struct lista {
	float info;         /* dado */
	struct lista *prox; /* ponteiro para o proximo elemento */
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

/* insere ordenado, retorna a lista atualizada */
Lista* lista_insere_ordenado( Lista *l, float info ){
Lista *L, *a = NULL, *p = l;
	L = (Lista*)malloc(sizeof(Lista));
	L->info = info;
	while(p!= NULL && p->info < info){
		a=p;
		p = p-> prox;
	}
	if(a==NULL){
		L->prox = l;
		l = L;
	}
	else{
		L->prox = a->prox;
		a->prox = L;
	}
	return l;
}

/* busca um elemento na lista e retorna-o caso ele seja encontrado */
Lista* lista_busca(Lista* l, float info )
{
	Lista* p = l;
	while(p != NULL) {
		if(p->info == info)
			return p;
		p = p->prox;
	}
	return NULL;
}

/* percorre os elementos, imprimindo-os */
void lista_imprime( Lista* l ) 
{
	Lista* p = l;
	while(p != NULL) {
		printf("%.2f\t", p->info);
		p = p->prox;
	}
	
	printf("\n");
}

/* percorre os elementos recursivamente, imprimindo-os */
void lista_imprime_rec( Lista* l ) 
{
	if(l != NULL) {
		printf("%.2f\t", l->info);
		lista_imprime_rec(l->prox);
	} else
		printf("\n");
}

/* remove da lista o elemento que contem 'info'. Se lista ficar vazia, retorna NULL.
   Se nao encontrou, retorna a lista 'l'.
   Senao, o elemento removido deve ser liberrado com free.
*/
Lista* lista_remove( Lista* l, float info )
{
	Lista* ant = NULL;
	Lista* p = l;
	
	//Procura o elemento
	while(p != NULL && p->info != info) {
		ant = p;
		p = p->prox;
	}	
	
	if(p != NULL) { //Caso encontrado
		if(ant == NULL) //remoção do primeiro elemento
			l = p->prox;
		else //
			ant->prox = p->prox;
		
		free(p);
	}
	
	return l;
}
/* libera a memória de cada nó da lista. */
void lista_destroi( Lista* l )
{
	Lista* elem = l;
	while( lista_vazia(elem) == false ){
		Lista* t = elem->prox;
		free(elem);
		elem = t;
	}
}