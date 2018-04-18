/*
 * lista.h
 * Definição da TAD Lista.
 */
#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdbool.h>
#include "ponto.h"

/* define o tipo Lista, derivado da 'struct lista' */
typedef struct lista Lista;

/* cria uma lista vazia, ou seja, retorna NULL */
Lista* lista_cria(void);

/* retorna se a lista esta vazia (true), ou false caso contrario */
bool lista_vazia( Lista* l );

/* insere no começo da lista, retorna a lista atualizada,
 * ou seja, o novo 1o elemento da lista.
 */
Lista* lista_insere( Lista* l, Ponto* ponto );

/* busca um elemento na lista e retorna-o caso ele seja encontrado */
Lista* lista_busca( Lista* l, Ponto* p );

/* imprime todos os elementos da lista */
void lista_imprime( Lista* l );

/* remove da lista o elemento que contem 'info'. Se lista ficar vazia, retorna NULL.
   Se não encontrou, retorna a lista 'l'.
   Senao, o elemento removido deve ser liberrado com free.
   ATENÇÃO: não libera memória dos dados.
*/
Lista* lista_remove( Lista* l, Ponto* p );

/* libera a memória de cada nó da lista.
 * ATENÇÃO: não libera memória dos dados.
 */
void lista_destroi( Lista* l );


#endif