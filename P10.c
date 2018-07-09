//Vitor Rabelo Cruvinel - 11721ECP004.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NCHAR_NOME 64

typedef struct Dimensoes{
	float largura, profundidade, altura;
}Dimensoes;

typedef struct Produto{
	char nome[NCHAR_NOME];
        float preco;
        Dimensoes dimensoes;
}Produto;

void Cadastrar(Produto * p){
	printf("\n\t\tDigite o nome do produto: ");
        fgets(p->nome, NCHAR_NOME, stdin);
        p->nome[strlen(p->nome)-1] = '\0';
        printf("\n\t\tDigite o preco: ");
        scanf("%f", &(p->preco));
        getchar();
        printf("\n\t\tDigite a largura: ");
        scanf("%f", &(p->dimensoes.largura));
        getchar();
        printf("\n\t\tDigite a profundidade: ");
        scanf("%f", &(p->dimensoes.profundidade));
        getchar();
        printf("\n\t\tDigite a altura: ");
        scanf("%f", &(p->dimensoes.altura));
        getchar();
}

void Consultar(Produto * p){
	char c;
        if(strlen(p->nome) == 0){
        	printf("\n\t\tProduto nao cadastrado!\n");
        	while((c=getchar()) != '\n');
        	return;
    	}
    	printf("\n\t\t%s, R$ %.2f, L: %.2fm x P: %.2fm x A: %.2fm\n", p->nome, p->preco, (p->dimensoes.largura), (p->dimensoes.profundidade), (p->dimensoes.altura));
}

int main(){
	int op1=-1, op2, np=0, i;
    	char c, file[NCHAR_NOME];
    	FILE * f;
    	Produto * produtos = (Produto *) calloc(1, sizeof(Produto));
    
    	while(op1 != 0){
        	printf("\n\t\tProdutos em memoria: %d", np);
        	printf("\n\t0. Sair\n\t1. Consultar\n\t2. Cadastrar novo\n\t3. Carregar de arquivo para memoria (sobrescreve memoria)\n\t4. Salvar memoria em arquivo (sobrescreve arquivo)\n\tOpcao: ");
        	scanf("%d", &op1);
        	getchar();
        	op2 = -1;
        	switch(op1){
                	case 1:
                		while(op2!=0){
                			if(np == 0){
                				printf("\nNenhum produto cadastrado!\n");
                				break;
					}
                			printf("\n\t\tConsulta de Produtos\n");
                        		printf("\n\t\tProdutos em memoria: %d", np);
                        		printf("\n\t\t0. Voltar");
                        		for(i=0; i<np; i++) printf("\n\t\t%d. %s", i+1, produtos[i].nome);
                        		printf("\n\t\tConsultar: ");
                        		scanf("%d", &op2);
                        		getchar();
                        		if(op2>0 && op2<=np) {Consultar(&produtos[op2-1]);break;}
                        		if(op2<=0 || op2>np) printf("\n\t\tProduto inexistente!\n");
                		}
                	break;
            		case 2:
            			np++;
                		produtos = (Produto *) realloc(produtos, np * sizeof(produtos));
                		Cadastrar(&produtos[np-1]);
                		printf("\n\t\tCadastrado com sucesso!\n");
                	break;
            		case 3:
            			printf("\n\t\tDigite o nome do arquivo: ");
            			scanf("%s", (char *)file);
            			getchar();
                		f = fopen(file, "rb");
                		if(f){
                        		fread(&np, sizeof(int), 1, f);
                        		produtos = (Produto *)calloc(np , sizeof(produtos));
                        		fread((void *)produtos, sizeof(produtos), np, f);
                        		fclose(f);
                			printf("\n\t\tArquivo contem %d produto(s). Leitura realizada com sucesso!\n", np);
                		}
				else{
                			printf("\n\t\tO arquivo nao pode ser aberto!\n");
                		}
                	break;
            		case 4:
            			printf("\n\t\tDigite o nome do arquivo: ");
            			scanf("%s", (char *)file);
            			getchar();
            			f = fopen(file, "wb");
                		if(f){
                			fwrite(&np, sizeof(int), 1, f);
                        		fwrite(produtos, sizeof(produtos), np, f);
                        		fclose(f);
                        		printf("\n\t\tProdutos armazenados em disco com sucesso!!\n");
                        		while((c=getchar()) != '\n');
                		}
				else{
                			printf("\n\t\tO arquivo nao pode ser aberto!\n");
                        		while((c=getchar()) != '\n');
                		}
                	break;
            		default:
            			if(op1!=0) printf("\n\tOpcao invalida!\n");
                	break;
        	}
    	}
    	free(produtos);
    	return 0;
}