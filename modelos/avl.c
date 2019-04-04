#include <stdio.h>
#include <stdlib.h>

typedef struct unidade {
    int altura, dado;
    struct unidade *esquerda, *direita;
} avl;

int max(int a, int b) {
    return (a > b)? a : b;
}

int altura(avl *unidade) {
    if (!unidade) return -1;
    return unidade->altura;
}

avl *esq_esq(avl *unidade) {
    avl *pivot = unidade->esquerda;
    unidade->esquerda = pivot->direita;
    pivot->direita = unidade;
    return pivot;
}

avl *dir_dir(avl *unidade) {
    avl *pivot = unidade->direita;
    unidade->direita = pivot->esquerda;
    pivot->esquerda = unidade;
    return pivot;
}

avl *esq_dir(avl *unidade) {
    unidade->esquerda = dir_dir(unidade->esquerda);
    return esq_esq(unidade);
}

avl *dir_esq(avl *unidade) {
    unidade->esquerda = esq_esq(unidade->direita);
    return dir_dir(unidade);
}

avl *criar(int valor) {
    avl *nova = malloc(sizeof(avl));
    nova->altura = 0;
    nova->dado = valor;
    nova->esquerda = nova->direita = NULL;
    return nova;
}

avl *inserir(avl *raiz, avl *unidade) {
    if (!raiz) return unidade;
    
    if (raiz->dado > unidade->dado) {
        raiz->esquerda = inserir(raiz->esquerda, unidade);
        if (altura(raiz->esquerda) - altura(raiz->direita) == 2) {
            if (raiz->esquerda->dado > unidade->dado)
                raiz = esq_esq(raiz);
            else raiz = esq_dir(raiz);
        }
    }
    else if (raiz->dado < unidade->dado) {
        raiz->direita = inserir(raiz->direita, unidade);
        if (altura(raiz->direita) - altura(raiz->esquerda) == 2) {
            if (raiz->direita->dado > unidade->dado)
                raiz = dir_dir(raiz);
            else raiz = dir_esq(raiz);
        }
    }
    raiz->altura = max(altura(raiz->esquerda), altura(raiz->direita)) + 1;
    return raiz;
}

void imprimir(avl *raiz) {
    if (!raiz) return;
    printf("%d\n", raiz->dado);
    imprimir(raiz->esquerda);
    imprimir(raiz->direita);
}

void libertar(avl *raiz) {
    if (!raiz) return;
    libertar(raiz->esquerda);
    libertar(raiz->direita);
    free(raiz);
}

int main() {
    avl *raiz = NULL;
    
    raiz = inserir(raiz, criar(5));
    raiz = inserir(raiz, criar(4));
    raiz = inserir(raiz, criar(3));
    
    imprimir(raiz);
    libertar(raiz);
    return 0;
}
