#include <stdio.h>
#include <stdlib.h>
typedef struct {
	char nome[50];
	char endereco[100];
	int matricula;
}estudante;
int main(){
	int *vetor,n,i;
	printf("Digite quantos alunos sera desejado: ");
	scanf("%d",&n);
	vetor= (int *) malloc(n*sizeof(estudante));
	estudante estudante[*vetor];
	for(i=0;i<n;i++){
		printf("Nome\n");
		scanf("%s",estudante[i].nome);
		printf("Endereço\n");
		scanf("%s",estudante[i].endereco);
		printf("Matricula\n");
		scanf("%d",&estudante[i].matricula);
		printf("\n");
	}
	system("clear");
	for(i=0;i<n;i++){
		printf("Estudante %d\n",i );
		printf("Nome: %s\n",estudante[i].nome);
		printf("Endereço: %s\n",estudante[i].endereco);
		printf("Matricula: %d\n",estudante[i].matricula);
		printf("\n");
	}

}