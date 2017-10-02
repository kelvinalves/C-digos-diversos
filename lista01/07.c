/* 07.c
 * potência
 * Calcular o valor de um número x
 * elevado a um número y.
 *
 * Autor: Kelvin Alves dos Santos
 * Data: 28/09/2017
 */

#include <stdio.h>

int main()
{
	int x, y, base;

	printf("Informe os inteiros x e y separando por espaço: ");
	scanf("%d %d", &x, &y);
	base = x;

	while (y > 1) {
		x *= base;
		y--;
	}
	printf("x ^ y = %d\n", x);
	
	return 0;
}
