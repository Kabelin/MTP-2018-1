//Vitor Rabelo Cruvinel - 11721ECP004.
#include <stdio.h>

int A(int,int);

int main(int argc, char ** argv) {
	int m,n;
	printf("Digite m e n:\n");
	scanf("%d%d",&m,&n);
	printf("\nResultado: %d",A(m,n));
	return 0;
}

int A(int m,int n){
	if(m==0) return n+1;
	else if((m>0) && (n==0)) return A(m-1,1);
	else if((m>0) && (n>0)) return A(m-1,A(m,n-1));
	return 0;
}
