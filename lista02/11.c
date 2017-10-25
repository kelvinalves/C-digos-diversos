#include <stdio.h>

int decBin(int dec)
{
  	if (dec <= 1) return dec;

  	return 10 * decBin(dec / 2) + dec % 2;
}

int binDec(int bin)
{
	int decimal  = 0, base = 1;

    	while(bin) {
        	decimal += bin % 10 * base;
        	bin /= 10;
        	base *= 2;
    	}
    	return decimal;
}

int main()
{
        int opcao, n;

        printf("Informe a opção desejada: ");
        scanf("%i", &opcao);

        if (opcao == 1) {
        	printf("Informe o número: ");
          	scanf("%i", &n);
          	printf("%i\n", decBin(n));
        }
        if (opcao == 2) {
          	printf("Informe o número: ");
          	scanf("%i", &n);
          	printf("%i\n", binDec(n));
        }
        return 0;
}  
