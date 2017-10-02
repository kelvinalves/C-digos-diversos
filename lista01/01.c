/* 01.c
 * parImpar
 * Classificar número informado
 * como par ou ímpar.
 *
 * Autor: Kelvin Alves dos Santos
 * Data: 22/09/2017
 */

#include <stdio.h>

main()
{
	int valor;

	printf("Informe um número inteiro: ");
	scanf("%d", &valor);
	
	if (valor%2==0) {
		printf("O número informado é par\n");
	} 
	else {
		printf("O número informado é ímpar\n");
	}
}
