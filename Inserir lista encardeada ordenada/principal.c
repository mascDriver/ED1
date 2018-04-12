#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lista.h"

int main(int argc, char **argv) {
	int op;
	float n;
	Lista *lista;
	lista = lista_cria();
	do{
	system("clear");
	printf("1- Inserir número\n2- Remover numero\n3- Buscar\n4- Imprimir\n0- Sair\n");
	printf("Digite a opçao desejada\n");
	printf("- ");	
	scanf("%d",&op);
		switch(op){
			case 1:
				printf("Digite o numero que deseja inserir\n");
				setbuf(stdin,NULL);
				scanf("%f",&n);
				lista=lista_insere_ordenado(lista, n);

				break;
			case 2:
				printf("Digite o numero que deseja remover\n");
				scanf("%f",&n);
				lista_remove(lista, n);
				break;
			case 3:
				printf("Digite o numero que deseja buscar\n");
				scanf("%f",&n);
				if(lista_busca(lista, n)!=NULL){
					printf("Existe\n");
				}
				else 
					printf("n existe\n");
				setbuf(stdin,NULL);
				getchar();
				break;
			case 4:
				lista_imprime_rec(lista);
				setbuf(stdin,NULL);
				getchar();
				break;
			case 0:

				break;
			default:
				printf("Opção invalida\n");
				break;
		}

	}while(op!=0);
	return 0;
}