//Vitor Rabelo Cruvinel - 11721ECP004.
#include <stdio.h>
int main(int argc, char ** argv) {
	char num[256];
	int i=0,aux,n=0;
	printf("Digite a string\n");
	scanf("%s", num);
	while(num[i]!='\0'){
		aux=48;
		while(aux>=48 && aux<=57){
			if(num[i]==aux) {printf("%c",num[i]);n++;}
			aux++;
		}
		i++;
	}
	if(n==0) printf("0");
	return 0;
}
