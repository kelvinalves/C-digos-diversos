#include <stdio.h>
#include <time.h>
#include <limits.h>

#define BIGNUM ULONG_MAX

typedef unsigned long int ulint;

ulint f1(ulint x)
{
	while (x >= 2) {
		if (x % 2 == 1) return 1;
		x /= 2;
	}
	return 0;
}

ulint f2(ulint x)
{
	while (x >= 2) {
		if (x % 2 == 1) return 1;
		x >>= 1;
	}
	return 0;
}

int main(void) 
{
	int x;
	clock_t tempo_init, tempo_fim;
	double tempo_gasto;
	ulint soma = 0;
  
	printf("Digite um número: ");
	scanf("%d", &x);

	tempo_init = clock();
	if (f1(x)) printf("O número não é potencia de 2\n");
	else printf("O número é potencia de 2\n");
	tempo_fim = clock();
  
	tempo_gasto = (double)(tempo_fim - tempo_init) / CLOCKS_PER_SEC;
	printf("Tempo gasto na versao normal : %lf\n", tempo_gasto);
  
	tempo_init = clock();
	if (f2(x)) printf("O número não é potencia de 2\n");
	else printf("O número é potencia de 2\n");
	tempo_fim = clock();
  
	tempo_gasto = (double)(tempo_fim - tempo_init) / CLOCKS_PER_SEC;
	printf("Tempo gasto na versao bitwise : %lf\n", tempo_gasto);
	return 0;
}
