#include <stdio.h>
#include <string.h>

void Imprime (int N) // função com um parâmetro por valor
{
	printf("%d", N);
}

void Set (int *N, int i) // função com um parâmetro por referência
{
      	*N = i;
}

int main()
{ 
        int i;
	int Vet[10];

        for (i=0; i< 10; i++) {
		Set(&Vet[i], i); // Note que é preciso colocar o '&' antes
                          // de Vet[i] pois a função 'Incr' espera um
                          // parâmetro por REFERÊNCIA

		Imprime(Vet[i]); // Note que NÃO se deve colocar nada antes
                            // de Vet[i] pois a função 'Imprime' espera um
                            // parâmetro por VALOR
	}
	return 0;  
}
