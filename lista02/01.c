#include <stdio.h>

int paridade(int num)
{
	int valor;
	valor = num % 2;  
	
	return valor;
}


int main ()
{
   	int num;
	
	printf("Digite um número: ");    
   	scanf("%i", &num);    
   	printf("%i\n", paridade(num));
	
	return 0;
}
