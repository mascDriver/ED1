#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
//setbuf(stdin,NULL);
//system("clear");

struct ponto {
	float x;
};

/* define o tipo Ponto, derivado da 'struct ponto' */
typedef struct ponto Ponto;

struct nodo {
	Ponto* dado;        /* ponteiro para o dado da lista Ponto */
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


bool compara_ponto(Ponto *a, Ponto *b);
void imprime_ponto(Ponto *p);
Sentinela* lista_remove( Sentinela* l, Ponto* p );
Sentinela* lista_insere(Sentinela *l,Ponto *ponto);
Ponto* ponto_cria(float x);
Sentinela* lista_cria(void);
bool lista_vazia( Sentinela* l );
int inserirelemento();
Sentinela* lista_remove( Sentinela* l, Ponto* p );
void imprimirelemento();
Sentinela*  insertrand(Sentinela* l, Ponto* ponto);
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
	srand(time(NULL));
	Sentinela *sentinela;
	Ponto *ponto;
	sentinela = lista_cria();
	char continuar[3];
	int n,i;
	float k,x;
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
					scanf("%f",&x);
					ponto = ponto_cria(x);
					sentinela = lista_insere(sentinela, ponto);
					break;
				case 2:
					printf("Qual número deseja excluir?\n");
					scanf("%f",&k);
					ponto = ponto_cria(k);
					sentinela = lista_remove(sentinela,ponto);
					break;
				case 3:
					imprimirelemento(sentinela);
					break;
				case 4:
					for(i=0;i<100;i++){
						k = (rand()%100)/3;
						ponto = ponto_cria(k);
						insertrand(sentinela,ponto);
					}
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


Ponto* ponto_cria(float x){
	Ponto *ponto = (Ponto*) malloc(sizeof(Ponto));
	ponto->x = x;
	return ponto;
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

Nodo* lista_busca( Sentinela* l, Ponto* p ) {
Nodo* elem = l->inicio;
	while(elem != NULL) {
		if(compara_ponto(elem->dado, p))
				return elem;
		elem = elem->prox;
	}
	
	return NULL;
}

Sentinela* lista_insere( Sentinela* l, Ponto *ponto)
{
	
 	Nodo *L = (Nodo*)malloc(sizeof(Nodo));
 	L->dado =ponto;
 	if(l->nItens == 0){
 		l->fim = L;
 		l->inicio = L;
 	}
 	else if(l->nItens>0){
 		L->prox = l->inicio;
 		l->inicio->ant = L;
 		l->inicio = L; 
 	}
 	else{
 		l->inicio = L;
 		l->inicio->ant = NULL;
 	}
 	l->nItens++;
 	return l;
}

Sentinela* lista_remove( Sentinela* l, Ponto* p ) {
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

void imprime_ponto(Ponto *p) {
	printf(" (%.2f)", p->x);
}

bool compara_ponto(Ponto *a, Ponto *b) {
	/* primeiro faz typecast dos ponteiros para Ponto */
	Ponto        *p1 = (Ponto *) a;
	Ponto        *p2 = (Ponto *) b;

	/* compara os pontos aqui */
	if (p1->x == p2->x)
		return true;

	return false;
}


void imprimirelemento(Sentinela *l){
	Nodo *tmp;
	if(lista_vazia(l))
		printf("%s: LISTA VAZIA!\n", __FUNCTION__);
	else {
		printf("(%s) EM ORDEM: ", __FUNCTION__);
		tmp = l->fim;
		while(tmp != NULL){
			imprime_ponto(tmp->dado);
			tmp = tmp->ant;
		}
		printf("\n\n");
	}
}
Sentinela*  insertrand(Sentinela* l, Ponto* ponto){
	
 	Nodo *L = (Nodo*)malloc(sizeof(Nodo));
 	L->dado =ponto;
 	if(l->nItens == 0){
 		l->fim = L;
 		l->inicio = L;
 	}
 	else if(l->nItens>0){
 		L->prox = l->inicio;
 		l->inicio->ant = L;
 		l->inicio = L; 
 	}
 	else{
 		l->inicio = L;
 		l->inicio->ant = NULL;
 	}
 	l->nItens++;
 	return l;
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

