#include <stdio.h>
#include <stdlib.h>
int main(){
	int j,**matriz,lin=4,col=4,i,*linha;
	matriz = (int**)malloc(lin*sizeof(int*)); 
	for(i=0;i<lin;i++)
		matriz[i]=(int*)malloc(lin*sizeof(int));
	for (i = 0; i < col; i++){
		for(j=0;j<col;j++){
			if(i==j){
				matriz[i][j]=1; 
			}
			else
				matriz[i][j]=0;
		}
	}
	for (i = 0; i < lin; i++){
		linha = matriz[i];
		for (j = 0; j < col; j++){
			printf(" %d ", linha[j]);
		}
		printf("\n");
	}
}