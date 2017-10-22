#include <stdio.h>

int fibMem[1000];

int fib (int n)
{
  	if (n == 0) return 0;
  	if (n <= 2) return 1;
  
  	fibMem[n] = fib (n-1) + fib (n-2);
  
  	return fib (n-1) + fib (n-2);
}

int main()
{
	int n;
	
	fibMem[1] = 1;
	fibMem[2] = 1;

	printf("Informe até qual termo imprimir: ");
	scanf("%i", &n);

	fib(n);
	
	for (int i = 0; i <= n; i++) {
		printf("%i ", fibMem[i]);
	}
	printf("\n");
	return 0;
}
