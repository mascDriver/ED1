#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encontra_letra(char *str, char letra, int *vet_indx, int *tam_vet_idx);

int main(){
	int vet_indx[50], tam_vet_idx=0,i;
	char str[50], letra;
	setbuf(stdin,NULL);
	scanf("%[^\n]s",str );
	setbuf(stdin,NULL);
	scanf("%c",  &letra);
	encontra_letra(str, letra, vet_indx, &tam_vet_idx);
	printf("%d \n",tam_vet_idx);
	for(i=0;i<strlen(str);i++){
		if(vet_indx[i]!=i){

		}
		else
		printf("%d ", vet_indx[i]);
	}

	
}

void encontra_letra(char *str, char letra, int *vet_indx, int *tam_vet_idx){
	int i;
	for(i=0;i<strlen(str);i++){
		if(str[i] == letra){
			*tam_vet_idx+=1;
			vet_indx[i]=i;
		}
	}
}
