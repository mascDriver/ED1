#include <stdio.h>
#include <stdlib.h>

void max_min();

int main(){
	int v[10],i,max,min;
	for(i=0;i<10;i++){
		v[i]=rand()%100;
	}
	max_min(v,i,&min,&max);
	printf("%d %d \n",max,min);
}

void max_min(int *v,int i, int *min, int *max){
	int aux=0;
	for(i=0;i<10;i++){
		if(aux<v[i]){
			aux=v[i];
			*max=v[i];
		}
	}
	for(i=0;i<10;i++){
		if(aux>v[i]){
			aux=v[i];
			*min=v[i];
		}
	}
	
}
