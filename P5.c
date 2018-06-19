//Vitor Rabelo Cruvinel - 11721ECP004.
#include <stdio.h>
int main(int argc, char ** argv) {
	int op,i,n[64],*pn;
	char str[256],*pm;
	for(i=0;i<256;i++) str[i] = 0;
	printf("\n\tEscolha uma opcao: \n\n\t1. Codificar\n\t2. Decodificar\n\n\tOpcao:");
	scanf("%d",&op); getchar();
	switch(op){
		case 1:
		{
			printf("\tDigite uma mensagem de ate 255 caracteres: \n\n\t");
			scanf("%s",str);getchar();
			printf("\n\tMensagem codificada: ");
			for(i=0;str[i];i++){
				pn = (int*)str;
				if(pn[i]!=0) printf("%d",pn[i]);
				if(pn[i+1]!=0) printf(", ");
			}
			break;
		}
		case 2:
		{
			printf("\tDigite uma sequencia numerica com ate 64 numeros, sendo o ultimo entre 1 e "
			"4095!\n\t(Obs:Digite 0 para finalizar a entrada de numeros)\n\n");
			for(i=0;i<64;i++) {
				printf("\tnumero %d: ", i+1); 
				scanf("%d", &n[i]);
				pm = (char*)n;
				if(n[i]==0) break;
			}
			printf("\n\tFrase decodificada: %s", pm);
		}
	}
	return 0;
}
