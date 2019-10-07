#include <stdio.h>
#include <stdlib.h>

typedef struct bloco
{
    int dado;
    struct bloco* seguinte;
}
lista;

lista* criar(int valor)
{
    lista* novo = malloc(sizeof(lista));
    novo->dado = valor;
    novo->seguinte = NULL;
    return novo;
}

lista* inserir(int valor, lista* primeiro)
{
    if (primeiro == NULL)
        return criar(valor);
    primeiro->seguinte = inserir(valor, primeiro->seguinte);
    return primeiro;
}

void imprimir(lista* primeiro)
{
    if (primeiro == NULL)
    {
        printf("[NULL]\n\n");
        return;
    }
    printf("[%d]->", primeiro->dado);
    imprimir(primeiro->seguinte);
}

void libertar(lista* primeiro)
{
    if (primeiro == NULL)
        return;
    libertar(primeiro->seguinte);
    free(primeiro);
}

void menu()
{
    int valor = 0, seletor = 0;
    lista* primeiro = NULL;
    
    do
    {
        printf("(1)\tInserir\n(2)\tImprimir\n(3)\tApagar\n(0)\tSair\n\n");
        scanf("%d", &seletor);
        
        switch (seletor)
        {
            case    0:  printf("Encerrado");
                        break;
                        
            case    1:  printf("Informe o valor: ");
                        scanf("%d", &valor);
                        primeiro = inserir(valor, primeiro);
                        break;
                        
            case    2:  imprimir(primeiro);
                        break;
                        
            case    3:  libertar(primeiro);
                        primeiro = NULL;
                        break;
                        
            default  :  printf("Informe um valor válido\n");
        }
    }
    while (seletor);
    
    if (primeiro)
        libertar(primeiro);
}

int main()
{
    menu();

    return 0;
}
