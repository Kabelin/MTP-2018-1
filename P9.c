//Vitor Rabelo Cruvinel - 11721ECP004.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Dimensoes{
	float largura, profundidade, altura;
};

struct Produto{
	char nome[64];
	float preco;
	struct Dimensoes dimensoes;
};

void Cadastrar(struct Produto P[], int i){
	printf("\n\t\tDigite o nome do produto: ");
	scanf("%s", &P[i].nome);
	printf("\n\t\tDigite o preco: ");
	scanf("%f", &P[i].preco);
	printf("\n\t\tDigite a largura: ");
	scanf("%f", &P[i].dimensoes.largura);
	printf("\n\t\tDigite a profundidade: ");
	scanf("%f", &P[i].dimensoes.profundidade);
	printf("\n\t\tDigite a altura: ");
	scanf("%f", &P[i].dimensoes.altura);
	printf("\n\t\tProduto %d cadastrado com sucesso!",i+1);
}

void Consultar(struct Produto P[], int i){
	if ((strcmp (P[i].nome, "") != 0) && (i==0||i==1))
		printf("\n\t\t\t%s, R$ %.2f, L: %.2fm x P: %.2fm x A: %.2fm\n", P[i].nome, P[i].preco, P[i].dimensoes.largura, P[i].dimensoes.profundidade, P[i].dimensoes.altura);
	else
		printf("\n\tProduto nao cadastrado!");	
}

int main(int argc, char ** argv) {
	int op=1, i=0;
	struct Produto P[1];
	strcpy(P[0].nome, "");
	strcpy(P[1].nome, "");
	
	while((op==1)||(op==2)){
		printf("\n\t1- Cadastro 2- Consulta\n\tOpcao: ");
		scanf("%d",&op);getchar();
		printf("\n\tProduto: ");
		scanf("%d",&i);getchar();
		switch(op)
		{
			case 1:
				Cadastrar(P,i-1);
			break;
			case 2:
				Consultar(P,i-1);
			break;
			default:
				return -1;
		}
	}
	return 0;
}
