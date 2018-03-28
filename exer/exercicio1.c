/*
https://github.com/mascDriver/ED1
Programa feito por: Diogo Baltazar
Com o intuito de unir 2 vetores digitados pelo usuario.
*/
#include <stdio.h>
#include <stdlib.h>

int *uniao(int *v1,int *v2,int n1,int n2);
int *uniaoconjunto(int *v1,int *v2,int n1,int n2);

int main(){
	int *v1,*v2,*v3,n1=4,n2=6;
	v1 =  (int *) malloc(n1*sizeof(int));
	v2 =  (int *) malloc(n2*sizeof(int));
	v3 =  (int *) malloc((n2+n1)*sizeof(int));
	printf("Digite os numeros: \n");
	for(int i=0;i<n1;i++){
		scanf("%d",&v1[i]);
	}
	for (int i = 0; i < n2; i++){
		scanf("%d",&v2[i]);	
	}
	v3=uniao(v1,v2,n1,n2);
	for(int i = 0 ;i<n1+n2;i++){
		printf(" %d ", v3[i]);
	}
	printf("\n");
	free(v1);
	free(v2);
	free(v3);
}

int *uniao(int *v1,int *v2,int n1,int n2){
	int *v3,i;
	v3 =  (int *) malloc((n2+n1)*sizeof(int));
	for(i=0;i<n1;i++){
		v3[i]=v1[i];
	}
	for(i=0;i<n2;i++){
		v3[i+n1]=v2[i];
	}
	return v3;
}

