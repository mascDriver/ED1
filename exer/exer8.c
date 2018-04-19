#include <stdio.h>
#include <stdlib.h>

enum boolean {
	true = 1, false = 0
};
typedef enum boolean bool;
int somaNumeros(int *n1, int *n2);

int main(){ 
	int n1=1,n2=1,soma;
	soma=somaNumeros(&n1,&n2);
	if(soma == true)
	printf("%d\n",soma );
	else
		printf("pq nao?\n");
}

int somaNumeros(int *n1, int *n2){
	int soma;
	soma = *n1+*n2;
	return 0;
}
