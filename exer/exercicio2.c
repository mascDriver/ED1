#include <stdio.h>
#include <stdlib.h>
int matriz_triangular_superior(int *matriz,int n);
int main(){
	int k=0,j,*matriz,lin,col,i,*linha,n,l;
	printf("o tanto de linhas desejadas seguido de o tanto de colunas desejadas\n");
	scanf("%d",&lin);
	scanf("%d",&col);
	printf("Agora digite os numeros da matriz\n");
	matriz = (int*)malloc((lin*col)*sizeof(int*)); 
	for (i = 0; i < lin*col; i++){
		scanf("%d",&matriz[i]);
	}
	for (i = 0; i < lin; i++){
		for(j=0;j<col;j++){	
			printf(" %d ", matriz[j+k]);
		}
		k+=j;
		printf("\n");
	}
		
	if(col==lin){
		n=lin;
		l=matriz_triangular_superior(matriz,n);
	}
	else
		printf("Nao eh uma matriz quadrada\n");	
	if(l)
		printf("matriz triangular superior\n");
	else
		printf("A matriz não é triangular superior\n");
	free(matriz);
	return 0;
}

int matriz_triangular_superior(int *matriz,int n){
	int k=0,j,cont=0,aux=0;
	for (int i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if(j<i && matriz[k+j]!=0){
				cont++;
			}
		}
		k+=j;
	}
	if(cont ==0 ){
		return 1;
	}
}
