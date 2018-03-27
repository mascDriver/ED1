#include <stdio.h>
#include <stdlib.h>
int main(){
	int *vetor,n,i,j,k,*newvetor,l=5;
	printf("Digite o numero desejado: ");
	vetor= (int *) malloc(5*sizeof(int));
	for(i=0;i<l;i++){
		scanf("%d",&vetor[i]);
		if(i==l-1){
			if(vetor[i]!=0){
				printf("novo vetor\n");
				newvetor =realloc(vetor,5*sizeof(int));
				vetor = newvetor;
				l+=5;

			}
		}
		else if(vetor[i]==0){
			break;
		}
		
	}
	for (i = 0; i < l; i++){
		printf("%d\n",vetor[i]);
	}	
}