#include <stdio.h>
#include <stdlib.h>
int main(){
	int v[4],i,j,aux;
	for (i = 0; i < 4; i++){
		scanf("%d",&v[i]);
	}
	for (i = 0; i < 4; i++){
		printf("%d ", v[i]);
	}
	/*for(i=1;i<4;i++){
		aux = v[i];
		for(j=i;(j>0)&&(aux<v[j-1]);j--)
			v[j] = v[j-1];
		v[j]=aux;
		
	}
	printf("\n");
	/*for(j=0;j<4;j++){
		for(i=0;i<4;i++){
			if(v[i]<v[i+1]){
				aux = v[i+1];
				v[i+1] = v[i];
				v[i] = aux;
			}
		}
	}*/
	for (i = 0; i < 4; i++){
		printf("%d ", v[i]);
	}
	
	
}