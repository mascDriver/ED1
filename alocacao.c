#include <stdio.h>
#include <stdlib.h>

int main(){
	int *p = (int *)malloc(sizeof(int)); //malloc
	int *a = (*int *)calloc(10,sizeof(int))//calloc
	int *pnew = realloc(p,20 * sizeof(int));
	free(p);
	if(!p)
		printf("Espãço insuficiente\n");
}