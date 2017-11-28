#include <stdio.h>
#include <time.h>
#include <limits.h>

#define BIGNUM ULONG_MAX

typedef unsigned long int ulint;

ulint f1(ulint x)
{
	if (x <= 1) return x;

	return 10 * f1(x / 2) + x % 2;
}

ulint f2(ulint x)
{
	if (x <= 1) return x;

	return 10 * f2(x >> 1) + x % 2;
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
	printf("%d\n", f1(x));
	tempo_fim = clock();
  
	tempo_gasto = (double)(tempo_fim - tempo_init) / CLOCKS_PER_SEC;
	printf("Tempo gasto na versao normal : %lf\n", tempo_gasto);
  
	tempo_init = clock();
	printf("%d\n", f2(x));
	tempo_fim = clock();
  
	tempo_gasto = (double)(tempo_fim - tempo_init) / CLOCKS_PER_SEC;
	printf("Tempo gasto na versao bitwise : %lf\n", tempo_gasto);
	return 0;
}
