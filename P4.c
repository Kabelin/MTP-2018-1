#include <stdio.h>
int main(int argc, char ** argv) {
	//Vitor Rabelo Cruvinel - 11721ECP004.
	char num[256];
	int i=0,aux;
	printf("Digite a string\n");
	scanf("%s",&num);
	while(num[i]!='\0'){
		aux=48;
		while(aux>=48 && aux<=57){
			if(num[i]==aux) printf("%c",num[i]);
			aux++;
		}
		i++;
	}
}