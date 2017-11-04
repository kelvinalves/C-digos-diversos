#include <stdio.h>
#include <stdlib.h>

/*exemplo de criação de um novo tipo de variável*/
typedef struct fracao {
 	int num;
 	int den;
} fracao;

int main ()
{
  	fracao x;
  	x.num = 1;
  	x.den = 2;
  
  	printf("numerador = %i\n", x.num);
	printf("denominador = %i\n", x.den);
}
