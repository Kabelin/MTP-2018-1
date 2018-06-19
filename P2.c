//Vitor Rabelo Cruvinel - 11721ECP004.

#include <stdio.h>

int Pot (int b, int e)
{
	int n = 1, eaux = 0;
	while(eaux != e)
	{
		n = n * b;
		eaux++;
	}
	return n;
}

int CParaI(char c)
{
	int n;
	if(c >= '0' && c <= '9')
	{
		n = c - '0';
	}
	else
	{
		n = c - 'A' + 10;
	}
	return n;
}

char IParaC(int n)
{
	char c;
	if(n < 10)
	{
		c = n + '0';
	}
	else
	{
		c = n - 10 + 'A';
	}
	return c;
}

void Mudanca(char bits[],int b1,int b2)
{
	int b;
	if(b1 == 2)
	{
		b=2;
	}
	else if (b1 == 8)
	{
		b=8;
	}
	else if (b1 == 16)
	{
		b=16;
	}
	else
	{
		b=10;
	}
	int i=0;
	while(bits[i]!='\0')
	{
		i++;
	}
	i--;
	int e = 0;
	int n = 0;
	while(i>=0)
	{
		n = n + (CParaI(bits[i]) * Pot(b,e));
		i--;
		e++;
	}

	b=0;
	if(b2 == 2)
	{
		b=2;
	}
	else if (b2 == 8)
	{
		b=8;
	}
	else if (b2 == 16)
	{
		b=16;
	}
	else
	{
		b=10;
	}
	e = 0;
	while(n/Pot(b,e) != 0)
	{
		e++;
	}
	e--;
	i=0;
	while((n != 0) || (e >= 0))
	{
		bits[i] = IParaC(n/Pot(b,e));
		n = n % Pot(b,e);
		i++;
		e--;
	}
	bits[i] = '\0';
	printf("\n\tO numero na base %d eh: %s",b,bits);
}

int main()
{
	char bits[256];
	int op=0;
	printf
	(
	"\nMudanca de bases:\n"
	"\n\t1. Binario para decimal"
	"\n\t2. Binario para hexadecimal"
	"\n\t3. Hexadecimal para Decimal"
	"\n\t4. Hexadecimal para Binario"
	"\n\t5. Decimal para Binario"
	"\n\t6. Decimal para Hexadecimal"
	"\n\t7. Octal para Decimal"
	"\n\t8. Decimal para Octal\n\n\tOpcao: "
	);
	scanf("%d",&op);
	getchar();
	printf("\n\tInsira os bits: ");
	scanf("%s",bits);
	getchar();
	switch(op)
	{
		case 1:
			Mudanca(bits,2,10);
		break;
		case 2:
			Mudanca(bits,2,16);
		break;
		case 3:
			Mudanca(bits,16,10);
		break;
		case 4:
			Mudanca(bits,16,2);
		break;
		case 5:
			Mudanca(bits,10,2);
		break;
		case 6:
			Mudanca(bits,10,16);
		break;
		case 7:
			Mudanca(bits,8,10);
		break;
		case 8:
			Mudanca(bits,10,8);
		break;
		default:
			return 0;
	}
	printf("\n");
	return 0;
}