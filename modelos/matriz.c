#include <stdio.h>
#include <stdlib.h>

void dobra(int tamanho, int **matriz){
    int ordem = (tamanho/2);
/*Alocação de memória de vetores multidimensionais modo A - via cast*/
    int **dobrada = malloc(ordem * sizeof(int *));
    for(int i = 0; i < ordem; i++)
        dobrada[i] = malloc(ordem * sizeof(int));
    if(dobrada == NULL){
        printf("Espaço insuficiente na memória!!\n");
        exit(1);
    }
    for(int i = 0; i < ordem; i++){
        for(int j = 0; j < ordem; j++)
            dobrada[i][j] = matriz[i][j] + matriz[i][tamanho-j-1] + matriz[tamanho-i-1][j] + matriz[tamanho-i-1][tamanho-j-1];
    }
    for(int i = 0; i < ordem; i++){
        for(int j = 0; j < ordem; j++)
            printf("%3d ", dobrada[i][j]);
        printf("\n");
    }
    for(int i = 0; i < ordem; i++)
        free(dobrada[i]);
    free(dobrada);
    }

int main() {
    int tamanho = 0;
    printf("Informe a ordem da matriz par: ");
    scanf("%d", &tamanho);
/*Alocação de memória de vetores multidimensionais modo B - via variável*/
    int **matriz = malloc(tamanho*sizeof(*matriz));
    for(int i = 0; i < tamanho; i++)
        matriz[i]=malloc(tamanho*sizeof(*(matriz[i])));
    if(matriz == NULL){
        printf("Espaço insuficiente na memória!!\n");
        exit(1);
    }
    for(int i=0; i<tamanho; i++){
        for(int j=0; j<tamanho; j++)
            matriz[i][j] = rand()%100;
    }
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++)
            printf("%2d ", matriz[i][j]);
        printf("\n");
    }
    dobra(tamanho, matriz);
    for(int i = 0; i < tamanho; i++)
        free(matriz[i]);
    free(matriz);
    return 0;
}
