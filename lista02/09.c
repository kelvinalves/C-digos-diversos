#include <stdio.h>

int potencia (int x, int y)
{
  	if (y == 1)
    		return x;
  
  	return x * potencia(x, y-1 );
}

int main()
{
	int x, y;

	printf("Informe os inteiros x e y separando por espaço: ");
	scanf("%i %i", &x, &y);
	printf("x ^ y = %i\n", potencia(x, y));
	
	return 0;
}
