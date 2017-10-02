/* 06.c
 * fatorial
 * Calcular o fatorial de um número x.
 *
 * Autor: Kelvin Alves dos Santos
 * Data: 22/09/2017
 */

#include <stdio.h>

int main()
{
	int x, fatorial = 1;

	printf("Informe um número inteiro x: ");
	scanf("%d", &x);

	while (x > 0) {
        	fatorial *= x;
        	x--;
	}
	printf("x! = %d\n", fatorial);
	
	return 0;
}
