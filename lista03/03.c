#include <stdio.h>
#include <stdlib.h>

int main ()
{
        int i;
        int v1[5], v2[5], v3[5];

        printf("Informe os vetores\n");
        for (i = 0; i < 5; i++) {
                printf("Informe o elemento %i de v1: ", i+1);
                scanf("%i", &v1[i]);

                printf("Informe o elemento %i de v2: ", i+1);
                scanf("%i", &v2[i]);

                v3[i] = v1[i] + v2[i];
                printf("v3[%i] =  %i\n", i+1, v1[i] + v2[i]);
        }
        return 0;
}
