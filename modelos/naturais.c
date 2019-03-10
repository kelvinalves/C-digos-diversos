#include <stdio.h>
#include <stdlib.h>

typedef struct natural {
    int numero;
    struct natural *proximo;
} lista;

lista *inserir(int n, lista *inicio);
void imprimir(lista *inicio);
void desalocar(lista *inicio);

int main() {
    int n = 0;
    lista *naturais = NULL;
    do {
        printf("Informe o número: ");
        scanf("%d", &n);
        switch(n) {
            case -1:
                printf("Fim de aquisições\n");
                break;
            default:
                naturais = inserir(n, naturais);
        }
    } while(n != -1);
    imprimir(naturais);
    desalocar(naturais);
    return 0;
}
lista *inserir(int n, lista *inicio) {
    lista *novo;
    novo = malloc(sizeof(lista));
    novo->numero = n;
    novo->proximo = NULL;
    if(inicio == NULL)
        return novo;
    lista *atual = inicio;
    while(atual->proximo != NULL)
        atual = atual->proximo;
    atual->proximo = novo;
    return inicio;
}
void imprimir(lista *inicio) {
    lista *index = inicio;
    while (index != NULL) {
        printf("\t%d", index->numero);
        index = index->proximo;
    }
}
void desalocar(lista *inicio) {
    lista *index = inicio;
    while (index != NULL) {
        index = index->proximo;
        free(inicio);
        inicio = index;
    }
}
