//Vitor Rabelo Cruvinel - 11721ECP004.

#include <stdio.h>
#include <stdlib.h>

void gera_numeros(float * vetor, int tam) {
	int i;
	float num;
	for(i = 0; i < tam; i++)
		vetor[i] =  (float) rand()/(float) RAND_MAX + 0.5f;
}

float reduce(float *inicio_vetor, float *fim_vetor, float (*funcao)(float, float)) 
{
	return (inicio_vetor == fim_vetor)? 1 : (*funcao)(*inicio_vetor, reduce(inicio_vetor+1, fim_vetor, funcao));
}

float soma(float n1, float n2){
	return n1+n2;
}

float produto(float n1, float n2){
	return 	n1*n2;
}

int main(int argc, char ** argv) {
	int op;
	float vetor[99];
	srand(123456);
	printf(
		"\nSoma e produto de 100 numeros aleatorios: "
		"\n\t1 - Somatorio"
		"\n\t2 - Produtorio"
		"\n\n\tOpcao: "
	);
	scanf("%d",&op);getchar();
	gera_numeros(vetor,99);
	switch (op)
	{
		case 1:
			printf("\n\tSoma: %f\n", reduce(vetor, vetor+99, soma)-1);
		break;
		case 2:
			printf("\n\tProdutorio: %f\n", reduce(vetor, vetor+99, produto));
		break;
		default:
			return -1;
	}
	return 0;
}