/* 04.c
 * multiplicação
 * Multiplicar 2 números informados.
 *
 * Autor: Kelvin Alves dos Santos
 * Data: 22/09/2017
 */

#include <stdio.h>

int main()
{
	int x, y;

	printf("Informe os inteiros x e y separando por espaço: ");
	scanf("%d %d", &x, &y);
	x *= y;
	printf("(x * y) = %d\n", x);
	
	return 0;
}
