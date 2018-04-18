/*
 * ponto.h
 * Definição da TAD Ponto.
 */
#ifndef _PONTO_H_
#define _PONTO_H_

#include <stdbool.h>

/* define a struct TAD ponto */
struct ponto {
	float x;
	float y;
};

/* define o tipo Ponto, derivado da 'struct ponto' */
typedef struct ponto Ponto;

/* cria um ponto */
Ponto* ponto_cria(float x, float y);

/* imprime um ponto */
void imprime_ponto(Ponto *p);

/* compara dois pontos */
bool compara_ponto(Ponto *p1, Ponto *p2);

/* libera um ponto */
void ponto_destroi(Ponto *p);

#endif