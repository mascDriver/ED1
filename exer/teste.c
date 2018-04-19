#include <stdio.h>
#include <stdlib.h>

void matriz_simples();
void matriz_duplo_ponteiro();
int main(){
	matriz_duplo_ponteiro();
}

void matriz_duplo_ponteiro(){
	int lin = 6, col = 4,*linha,i,j;
	int **matriz = (int **) malloc(lin*col*sizeof(int*));
	for(i=0;i<lin;i++){
		matriz[i]= (int*) malloc(lin*col*sizeof(int*));
	}
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			matriz[i][j]=((i+1)*10)+(j+1);
		}
	}
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf(" %d ",matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<lin;i++){
		linha = matriz[i];
		for(j=0;j<col;j++){
			printf(" %d ",linha[j]);
		}
		printf("\n");
	}


}

void matriz_simples(){
	int i,j,lin = 4, col = 6;
	int *matriz = (int *) malloc(lin * col *sizeof(int*));
	for(i=0;i<lin;i++){
		for(j=0; j<col;j++){
			matriz[i*col+j] = ((i+1)*10)+(j+1);
		}
	}
	for(i=0;i<lin;i++){
		for(j=0; j<col;j++){
			printf(" %d ",matriz[i*col+j]);
		}
		printf("\n");
	}
}
