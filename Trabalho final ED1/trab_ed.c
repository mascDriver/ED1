
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
//setbuf(stdin,NULL);
//system("clear");

struct ponto {
	int x;
};

/* define o tipo Ponto, derivado da 'struct ponto' */
typedef struct ponto Ponto;

struct nodo {
	Ponto* dado;        /* ponteiro para o dado da lista Ponto */
	float valor;
	struct nodo *prox; /* ponteiro para o proximo elemento */
	struct nodo *ant;  /* ponteiro para o elemento anterior */
};
typedef struct nodo Nodo;
/* define a struct TAD sentinela */
struct sentinela {
	int nItens;          /* número de elementos na lista. Atualizar ao inserir e remover da lista */
	struct nodo *inicio; /* ponteiro para o primeiro elemento da lista */
	struct nodo *fim;  /* ponteiro para o último elemento da lista */
};
typedef struct sentinela Sentinela;

void lista_insere(Sentinela *l,float x);
Sentinela* lista_cria(void);
bool lista_vazia( Sentinela* l );
int inserirelemento();
Sentinela* lista_remove( Sentinela* l, float p );
void imprimirelemento(Sentinela* l);
void  insertrand(Sentinela* l, float x);
Sentinela* isort(Sentinela *l);
Sentinela* ssort(Sentinela *l);
int qusort();
int msort();
bool verificacao(char continuar[]);
void menu();
int main(int argc, char const *argv[]){
	menu();	
	return 0;
}

void menu(){
	srand(time(NULL));
	Sentinela *sentinela;
	sentinela = lista_cria();
	char continuar[3];
	int n,i;
	int k,x;
	do{
		system("clear");
		printf("Digite\n1 - inserir elemento\n2 - excluir elemento\n3 - imprimir\n4 - fazer inserção de 100 elementos aleatórios\n5 - Ordenar via Insert Sort\n6 - Ordenar via Selection sort\n7 - Ordenar via Quick Sort\n8 - Ordenar via Merge sort\n");
		printf("What your mind? \n");
		scanf("%d",&n);

		if(n>7 || n< 1){
			break;
		}
		switch(n){
			do{
				case 1:
					printf("Deseja inserir qual número?\n");
					scanf("%d",&x);
					lista_insere(sentinela,x);
					break;
				case 2:
					printf("Qual número deseja excluir?\n");
					scanf("%d",&k);
					sentinela = lista_remove(sentinela,k);
					break;
				case 3:
					imprimirelemento(sentinela);
					break;
				case 4:
					for(i=0;i<100;i++){
						k = (rand()%100);
						insertrand(sentinela,k);
					}
					break;
				case 5:
					sentinela = isort(sentinela);
					break;
				case 6:
					ssort(sentinela);
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




Sentinela* lista_cria(void)
{
	//Método pronto - cria a lista vazia a partir da sentinela
	Sentinela *sentinela = (Sentinela*) malloc(sizeof(Sentinela));
	sentinela->nItens = 0;
	sentinela->inicio = NULL;
	sentinela->fim  = NULL;
	return sentinela;
}

bool lista_vazia( Sentinela* l )
{
	
	return (l == NULL);
}

Nodo* lista_busca( Sentinela* l, float p) {
Nodo* elem = l->inicio;
	while(elem != NULL) {
		if(elem->valor, p)
				return elem;
		elem = elem->prox;
	}
	
	return NULL;
}

void lista_insere( Sentinela* l, float x)
{
	
 	Nodo *L = (Nodo*)malloc(sizeof(Nodo));
 	L->valor = x;
 	if(l->nItens == 0){
 		l->fim = L;
 		l->inicio = L;
 		l->inicio->prox = NULL;
 		l->fim->ant = NULL;
 		l->inicio->ant = NULL;
 		l->fim->prox = NULL;
 	}
 	else{
 		L->ant = l->fim;
 		l->fim->prox = L;
 		l->fim = L; 
 		l->fim->prox = NULL;
 	}
 	
 	l->nItens++;
}
void  insertrand(Sentinela* l,float x){
	
 	Nodo *L = (Nodo*)malloc(sizeof(Nodo));
 	L->valor = x;
 	if(l->nItens == 0){
 		l->fim = L;
 		l->inicio = L;
 		l->inicio->prox = NULL;
 		l->fim->ant = NULL;
 		l->inicio->ant = NULL;
 		l->fim->prox = NULL;
 	}
 	else{
 		L->ant = l->fim;
 		l->fim->prox = L;
 		l->fim = L; 
 		l->fim->prox = NULL;
 	}
 	l->nItens++;
}
void imprimirelemento(Sentinela* l){
	Nodo *tmp = l->inicio;
	while(tmp!= NULL){
		printf("(%.2f) ", tmp->valor);
		tmp = tmp->prox;
	}
	printf("\n\n");
}

Sentinela* lista_remove( Sentinela* l, float p ) {
	Nodo *r = lista_busca(l,p);
	
	printf("antes de excluir %d\n",l->nItens );
	if(r == NULL){ //Caso não encontrado
		//l->nItens--;
		return l;
	}
	else{
		if(r->ant == NULL) { //Caso for o primeiro
			if(l->fim->prox != NULL) //Caso possua um proximo, seta seu anterior para NULL
				l->fim->prox->ant = NULL;
			l->fim = l->fim->prox;

			}else if(r->prox == NULL) { //Caso for o último
				r->ant->prox = NULL;
		
			}else{ //Caso for nó do meio
				r->ant->prox = r->prox;
				r->prox->ant = r->ant;
		}
		l->inicio = r->prox;
		l->nItens--;
	}
		free(r);

	printf("depois de exluir %d\n",l->nItens );
	return l;
}

bool verificacao(char continuar[]){
	if(continuar[0]!='n'){
		return true;	
	}
	else{
		return false;
	}
}
Sentinela* isort(Sentinela *l){
	if(l->nItens<=1){
		printf("A lista está vazia\n");
		return l;
	}
	int i=0;
	printf("%d\n",l->nItens);
	Nodo *prox=l->inicio->prox, *ant=prox->ant;

	while(prox!=NULL){
		ant=prox->ant;
		printf("%p\n", ant);
		while(ant!=NULL){
			if(ant->valor > prox->valor){
				if(l->nItens==2){
					ant->prox = NULL;
					ant->ant = prox;
					prox->prox = ant;
					prox -> ant = NULL;
					l->inicio = ant;
					l->fim = prox;
				}
				else if(ant->ant ==NULL && prox -> prox != NULL){
					prox->prox->ant = ant;
					ant -> prox = prox->prox;
					ant->ant = prox;
					prox->prox = ant;
					prox->ant = NULL;
					l->inicio = prox;
				}
				else if(ant->ant!=NULL && prox->prox==NULL){
					ant->ant->prox = prox;
					prox->ant = ant ->ant;
					ant->prox = NULL;
					ant->ant = prox;	
					prox->prox = ant;
					l->fim = ant;
				}
				else if(ant -> ant !=NULL && prox ->prox != NULL){
					prox->prox->ant=ant;
					ant->ant->prox=prox;
					prox->ant=ant->ant;
					ant->prox=prox->prox;
					ant->ant=prox;
					prox->prox=ant;
				}
			}
			ant = ant->ant;
		}
		prox=prox->prox;
	}
	return l;
}
Sentinela* ssort(Sentinela *l){
	Nodo *atual = l->inicio, *prox = atual->prox,*min;
	while(atual!=NULL){
		prox = atual->prox;
		min = prox;
		while(prox!=NULL){
			if(prox->valor < min->valor)
				min = prox;
			prox = prox->prox;

		}
		atual = atual->prox;
	}

	return l;
}
int qusort(){
	return 0;
}
int msort(){
	return 0;
}