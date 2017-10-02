/* 08.c
 * fibonacci
 * Imprimir a sequência de fibonacci até o termo i.
 *
 * Autor: Kelvin Alves dos Santos
 * Data: 28/09/2017
 */

#include <stdio.h>

int main()
{
	int termo, termo_0 = 0, termo_1 = 1;

	printf("Informe até qual termo imprimir: ");
	scanf("%d", &termo);
	
	if (termo) {
		printf("%d %d ", termo_0, termo_1);
  		for (int i = 1; i < termo; i++) {
			termo_1 += termo_0;
			termo_0 = termo_1 - termo_0;
			printf("%d ", termo_1);
		}
	printf("\n");
	}
	else {
		printf("%d \n", 0);
	}
	return 0;
}
