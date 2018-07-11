#include <stdio.h>
#include <stdlib.h>
/* Lista para o tratamento das colisões (encadeamento separado) */
struct lista {
int info;
/* dado */
struct lista *prox; /* ponteiro para o próximo elemento */
};
typedef struct lista Lista;
/* Estrutura da tabela hash */
struct hash {
Lista **tab; /* vetor com as listas da tabela hash */
int tam;
/* tamanho da tabela hash */
};
typedef struct hash Hash;

int main(){
	int n;
	do{
		scanf("%d",&n);
		switch(n){
			case 1:
				break;
		}
	}while(n!=0);
}