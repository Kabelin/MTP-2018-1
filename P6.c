//Vitor Rabelo Cruvinel - 11721ECP004.
#include <stdio.h>

int soma(int*,int*);
float div(float,float);

int main(int argc, char ** argv) {
	int n[20],q,i=0;
	while(i<20){
		n[i]=0;
		i++;
	}
	i=0;
	printf("Qual a quantidade de numeros?\n");
	scanf("%d",&q);getchar();
	while(i<q){
		printf("Numero %d: \n",i+1);
		scanf("%d",&n[i]);getchar();
		i++;
	}
	printf("Media = %f",div(q,(soma(&n[0],&n[q-1]))));
	return 0;
}

int soma(int *ref,int *px){
	return (*px) + ((ref == px) ? 0 : soma(ref, px-1));
}
float div(float q, float n){
	return n/q;
}
