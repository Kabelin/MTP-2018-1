//Vitor Rabelo Cruvinel - 11721ECP004.
#include <stdio.h>
int main(int argc, char ** argv) {
	int estado = 0, i = 0;
	char bits [256];
	printf("Digite o numero desejado: ");
	scanf("%s", &bits);
	while(bits[i] != '\0')
	{
		if(estado == 0 && bits[i] == '0') estado = 0;
		else if (estado == 0 && bits[i] == '1') estado = 1;
		else if (estado == 1 && bits[i] == '0') estado = 2;
		else if (estado == 1 && bits[i] == '1') estado = 0;
		else if (estado == 2 && bits[i] == '0') estado = 1;
		else if (estado == 2 && bits[i] == '1') estado = 2;
		i++;
	}
	printf("\nO valor do estado eh: %d",estado);
	if(estado == 0) printf("\nA sequencia %s eh multipla de tres",bits);
	else printf("\nA sequencia %s nao eh multipla de tres",bits);
	return 0;
}
