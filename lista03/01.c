#include <stdio.h>
#include <stdlib.h>

int main ()
{
  	int n;
  	char palavra[46];
  
  	printf("Digite uma palavra: ");
  	fgets(palavra, sizeof(palavra), stdin);
  
  	n = contaVogais(palavra);
  
  	if (n > 1) printf("A palavra informada tem %i vogais\n", n);
  	else if (n == 1) printf("A palavra informada tem %i vogal\n", n);
  	else printf("A palavra informada não possui vogais\n");
  
  	return 0;
}

int contaVogais(const char *str)
{
  	int i, cont = 0;
  	char vogais[10] = "AaEeIiOoUu";
  
  	while (*str) {
    		for (i = 0; i < sizeof(vogais); i++) if (*str == vogais[i]) cont++;
    	str++;
  	}
	return cont;
}
