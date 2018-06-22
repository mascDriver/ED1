#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ponto {
	int x;
};

/* define o tipo Ponto, derivado da 'struct ponto' */
typedef struct ponto Ponto;

struct nodo {
	Ponto* dado;        /* ponteiro para o dado da lista Ponto */
	struct nodo *prox; /* ponteiro para o proximo elemento */
	struct nodo *ant;  /* ponteiro para o elemento anterior */
};

/* define a struct TAD sentinela */
struct sentinela {
	int nItens;          /* número de elementos na lista. Atualizar ao inserir e remover da lista */
	struct nodo *inicio; /* ponteiro para o primeiro elemento da lista */
	struct nodo *fim;  /* ponteiro para o último elemento da lista */
};

int inserirelemento();
int excluirelemento();
void imprimirelemento();
int insertrand();
int isort();
int ssort();
int qusort();
int msort();
bool verificacao(char continuar[]);
void menu();
int main(int argc, char const *argv[]){
	menu();	
	return 0;
}

void menu(){
	char continuar[3];
	int n;
	do{
		printf("Digite\n1 - inserir elemento\n2 - excluir elemento\n3 - imprimir\n4 - fazer inserção de 100 elementos aleatórios\n5 - Ordenar via Insert Sort\n6 - Ordenar via Selection sort\n7 - Ordenar via Quick Sort\n8 - Ordenar via Merge sort\n");
		printf("What your mind? \n");
		scanf("%d",&n);
		switch(n){
			do{
				case 1:
					inserirelemento();
					break;
				case 2:
					excluirelemento();
					break;
				case 3:
					imprimirelemento();
					break;
				case 4:
					insertrand();
					break;
				case 5:
					isort();
					break;
				case 6:
					ssort();
					break;
				case 7:
					qusort();
					break;
				case 8:
					msort();
					break;
				default:
					printf("a\n");
					break;
			}while(n>7 || n< 1);
		}
		printf("Deseja continuar?\n");
		scanf("%s",continuar);
	}while(verificacao(continuar));
}

bool verificacao(char continuar[]){
	if(continuar[0]=='s'){
		return true;	
	}
	else{
		return false;
	}
}
int inserirelemento(){
	return 0;
}
int excluirelemento(){
	return 0;
}
void imprimirelemento(){

}
int insertrand(){
	return 0;
}
int isort(){
	return 0;
}
int ssort(){
	return 0;
}
int qusort(){
	return 0;
}
int msort(){
	return 0;
}

