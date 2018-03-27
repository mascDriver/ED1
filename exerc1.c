#include <stdio.h>
void calcula_quadrado();
int main(){
	int lado;
	float  area, perimetro;
	scanf("%d",&lado);
	calcula_quadrado(lado, &area, &perimetro);
	printf("\n%d \n%.2f \n%.2f", lado, area, perimetro);

}
void calcula_quadrado(int lado, float *area, float*perimetro){
	*area = lado*lado;
	*perimetro = lado+lado+lado+lado;

}

