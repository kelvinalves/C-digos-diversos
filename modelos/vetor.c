#include <stdio.h>
#include <stdlib.h>
void main()
{
  	int i;
  	int *v;
  	v = (int*)malloc(sizeof(int)*10);  	// 'v' é um ponteiro para uma área que
                                     		// tem 10 inteiros.
                                     		// 'v' funciona exatamente como um vetor
  	for (i = 0; i < 10; i++) v[i] = 10+i;

  	for(i = 0; i < 10; i++) printf("v[%d]: %d\n", i, v[i]);

  	printf("Endereço de 'v': %p", v);  	// imprime o endereço da área alocada para 'v'
  	free(v);
}
