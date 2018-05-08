#include <stdio.h>
void cv (int num)
{
	unsigned int aux2;
	int bin[31];
	int aux=31;
	while(aux>=0){
		bin[aux] = 0;
		aux--;
	}
	aux=31;
	if(num>0){
		while(num>0){
	        	if (num % 2 == 0) {
        			bin[aux] = 0;
            			num = num / 2;
        		}
        		else {
            			bin[aux] = 1;
            			num = num / 2;
       			}
			aux--;
		}
    		for (aux = 0; aux <= 31; aux++) 
		{
        		printf("%d", bin[aux]);
    		}
	}
	if(num<0){
		aux2 = -num;
		aux2 = ~aux2 +1;
		while(aux2>0){
	        	if (aux2 % 2 == 0) {
        			bin[aux] = 0;
            			aux2 = aux2 / 2;
        		}
        		else {
            			bin[aux] = 1;
            			aux2 = aux2 / 2;
       			}
			aux--;
		}
		for (aux = 0; aux <= 31; aux++) 
		{
        		printf("%d", bin[aux]);
    		}
	}

}

int main(int argc, char ** argv) {
	//Vitor Rabelo Cruvinel - 11721ECP004.
	int a,b,op;
	printf("Digite a opcao desejada: 1-NOT, 2-AND, 3-OR, 4-XOR, 5-Right Shift e 6-Left Shift\n");
	scanf("%d",&op);getchar();
		switch(op)
	{
		case 1:
			printf("\nDigite o argumento em inteiro:\n");
			scanf("%d",&a);getchar();
			printf("\nNOT %d (",a );
			cv(a);
			printf(") : %d (",~a);
			cv(~a);
			printf(")");
			break;

		case 2:
			printf("\nDigite o primeiro argumento em inteiro:\n");
			scanf("%d",&a);getchar();
			printf("\nDigite o segundo argumento em inteiro:\n");
			scanf("%d",&b);getchar();
			printf("\n%d (",a);
			cv(a);
			printf(") AND %d (",b);
			cv(b);
			printf(") : %d (",a&b);
			cv(a&b);
			printf(")");
			break;

		case 3:
			printf("\nDigite o primeiro argumento em inteiro:\n");
			scanf("%d",&a);getchar();
			printf("\nDigite o segundo argumento em inteiro:\n");
			scanf("%d",&b);getchar();
			printf("\n%d (",a);
			cv(a);
			printf(") OR %d (",b);
			cv(b);
			printf(") : %d (",a|b);
			cv(a|b);
			printf(")");
			break;

		case 4:
			printf("\nDigite o primeiro argumento em inteiro:\n");
			scanf("%d",&a);getchar();
			printf("\nDigite o segundo argumento em inteiro:\n");
			scanf("%d",&b);getchar();
			printf("\n%d (",a);
			cv(a);
			printf(") XOR %d (",b);
			cv(b);
			printf(") : %d (",a^b);
			cv(a^b);
			printf(")");
			break;

		case 5:
			printf("\nDigite o argumento em inteiro:\n");
			scanf("%d",&a);getchar();
			printf("\nDigite a quantidade do deslocamento:\n");
			scanf("%d",&b);getchar();
			printf("\n%d (",a);
			cv(a);
			printf(") >> %d (",b);
			cv(b);
			printf(") : %d (",a>>b);
			cv(a>>b);
			printf(")");
			break;

		case 6:
			printf("\nDigite o argumento em inteiro:\n");
			scanf("%d",&a);getchar();
			printf("\nDigite a quantidade do deslocamento:\n");
			scanf("%d",&b);getchar();
			printf("\n%d (",a);
			cv(a);
			printf(") << %d (",b);
			cv(b);
			printf(") : %d (",a<<b);
			cv(a<<b);
			printf(")");
			break;

		default:
		printf("\nValor invalido");
	}
}