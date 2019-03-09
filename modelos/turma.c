/*Biblioteca*/
#include <stdio.h>
#include <stdlib.h>
/*Estrutura*/
typedef struct aluno {
    int ra;
    double nota;
    char *nome;
    struct aluno *proximo;
} turma;
/*Protótipos*/
int comprimento(char *nome);
turma *cria_aluno(int ra, char *nome, double nota);
turma *inserir(turma *primeiro, int ra, char *nome, double nota);
void imprimir(turma *inicio);
void liberar_memoria(turma *inicio);
/*Código*/
int main() {
    int i = 0, n = 0, ra = 0;
    char nome[50];
    double nota = 0;
    turma *aed1 = NULL;
    printf("Informe o tamanho da turma: ");
    scanf("%d", &n);
    while(i < n) {
        i++;
        printf("\n%dº\nNome: ", i);
        scanf("%s", nome);
        printf("RA: ");
        scanf("%d", &ra);
        printf("Nota: ");
        scanf("%lf", &nota);
        aed1 = inserir(aed1, ra, nome, nota);
    }
    imprimir(aed1);
    liberar_memoria(aed1);
    return 0;
}
int comprimento(char *nome) {
    int tamanho = 0;
    char *index = nome;
    while(*index != '\0') {
        index++;
        tamanho++;
    }
    return tamanho;
}
turma *cria_aluno(int ra, char *nome, double nota) {
    int tamanho = comprimento(nome);
    char *index = nome;
    while(*index != '\0') {
        index++;
        tamanho++;
    }
    turma *novo = NULL;
    novo = malloc(sizeof(turma));
    novo->ra = ra;
    novo->nome = malloc(tamanho * sizeof(char));
    for (int i = 0; i < tamanho; i++) {
        novo->nome[i] = *nome;
        nome++;
    }
    novo->nota = nota;
    novo->proximo = NULL;
    return novo;
}
turma *inserir(turma *primeiro, int ra, char *nome, double nota) {
    turma *aluno = cria_aluno(ra, nome, nota);
    if (primeiro == NULL)
        return aluno;
    else {
        turma *atual = primeiro; 
        while (atual->proximo != NULL)
            atual=atual->proximo;
        atual->proximo = aluno;
        return primeiro;
    }
}
void imprimir(turma *inicio) {
    turma *i = inicio;
    while(i != NULL) {
        printf("Nome: %s RA: %d Nota: %.2lf\n", i->nome, i->ra, i->nota);
        i = i->proximo;
    }
}
void liberar_memoria(turma *inicio) {
    turma *i = inicio;
    while(i != NULL) {
        i = i->proximo;
        free(inicio->nome);
        free(inicio);
        inicio = i;
    }
}
