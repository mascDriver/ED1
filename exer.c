#include <stdio.h>
#include <stdlib.h>

void imprime();

int main(){
	char v;
	int n;
	scanf("%d",&n);
	v = 'a';
	imprime(&v,n);
}

void imprime(char *v, int n){
	char *c;
	for(c=v;c<v+n;c++){
		printf("%c",*c);
	}
}