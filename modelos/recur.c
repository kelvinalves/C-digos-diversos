#include <stdio.h>
#include <stdlib.h>

void recursivo(int numero){
	if(numero==0)
	  return;
	printf("A%d",numero);
	recursivo(numero-1);
	printf("B%d",numero);
}
int main(){
	int numero;
	printf("Digite um numero: ");
	scanf("%d",&numero);
	recursivo(numero);
	return 0;
}
