#include <stdio.h>

void soma()
{
	float x, y;

	printf("Informe x e y separando por espaço: ");
	scanf("%f %f", &x, &y);
	x += y;
	printf("(x + y) = %.2f\n", x);
}

void subtracao()
{
	float x, y;

	printf("Informe x e y separando por espaço: ");
	scanf("%f %f", &x, &y);
	x -= y;
	printf("(x - y) = %.2f\n", x);
}

void multiplicacao()
{
	float x, y;

	printf("Informe x e y separando por espaço: ");
	scanf("%f %f", &x, &y);
	x *= y;
	printf("(x * y) = %.2f\n", x);
}

void divisao()
{
	float x, y;

	printf("Informe x e y separando por espaço: ");
	scanf("%f %f", &x, &y);
	x /= y;
	printf("(x / y) = %.2f\n", x);
}

void potencia()
{
	float x, y, base;

	printf("Informe x e y separando por espaço: ");
	scanf("%f %f", &x, &y);
	base = x;

	while (y > 1) {
		x *= base;
		y--;
	}
	printf("x ^ y = %.2f\n", x);
}

int main ()
{
    	int opcao;

    	printf("Selecione a operação desejada: ");
	scanf("%d", &opcao);
    	if (opcao == 1) {
    		soma();
    	} 
    	if (opcao == 2) {
    		subtracao();
    	}
    	if (opcao == 3) {
    		multiplicacao();
    	}
    	if (opcao == 4) {
    		divisao();
    	}
    	if (opcao == 5) {
    		potencia();
    	}

	return 0;
}
