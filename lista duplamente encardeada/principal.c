/*
 * principal.c Programa que testa a TAD Lista - lista duplamente encadeada.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "lista.h"
#include "ponto.h"

int main(int argc, char **argv) {
	Lista *lista;
	Ponto *p1, *p2, *p3, *p4;

	/* cria a lista */
	lista = lista_cria();
	
	/* cria pontos e os insere na lista */
	printf("Criando e inserindo os elementos (P1 a P4)...\n");
	p4 = ponto_cria(4.0, 4.0);
	lista = lista_insere(lista, p4);
	
	p3 = ponto_cria(3.0, 3.0);
	lista = lista_insere(lista, p3);
	
	p2 = ponto_cria(2.0, 2.0);
	lista = lista_insere(lista, p2);
	
	p1 = ponto_cria(1.0, 1.0);
	lista = lista_insere(lista, p1);
	
	/* imprime todos */
	printf("\nLista inicial...\n");
	lista_imprime( lista );
	
	/* remove primeiro elemento */
	printf("\nRemovendo P1 (primeiro elemento)...\n");
	lista = lista_remove(lista, p1);
	if(! lista_busca(lista, p1)) 
		printf("SUCESSO! P1 foi removido.\n");
	else
		printf("ERRO! P1 continua na lista.\n");
	
	/* remove elemento do meio */
	printf("Removendo P3 (elemento do meio)...\n");
	lista = lista_remove(lista, p3);
	if(! lista_busca(lista, p3)) 
		printf("SUCESSO! P3 foi removido.\n");
	else
		printf("ERRO! P3 continua na lista.\n");
	
	/* remove último elemento */
	printf("Removendo P4 (último elemento)...\n");
	lista = lista_remove(lista, p4);
	if(! lista_busca(lista, p4)) 
		printf("SUCESSO! P4 foi removido.\n");
	else
		printf("ERRO! P4 continua na lista.\n");
	
	/* remove último elemento */
	printf("Removendo P2...\n");
	lista = lista_remove(lista, p2);
	if(! lista_busca(lista, p2)) 
		printf("SUCESSO! P2 foi removido.\n");
	else
		printf("ERRO! P2 continua na lista.\n");
	
	/* imprime todos */
	printf("\nLista final...\n");
	lista_imprime( lista );
	
	printf("\nInserindo P1...\n");
	lista = lista_insere(lista, p1);
	if(lista_busca(lista, p1)) 
		printf("SUCESSO! P1 foi inserido.\n");
	else
		printf("ERRO! P1 não econtrado.\n");
	
	printf("Inserindo P3...\n");
	lista = lista_insere(lista, p3);
	if(lista_busca(lista, p3)) 
		printf("SUCESSO! P3 foi inserido.\n");
	else
		printf("ERRO! P3 não econtrado.\n");
	
	/* imprime todos */
	printf("\nLista final...\n");
	lista_imprime( lista );
	
	/* libera a memória */
	printf("\nLiberando a memória...\n");
	lista_destroi(lista);
	ponto_destroi(p1);
	ponto_destroi(p2);
	ponto_destroi(p3);
	ponto_destroi(p4);

	return 0;
}