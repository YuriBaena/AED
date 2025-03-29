#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Cria uma fila com capacidade definida
Fila* cria_fila(int capacidade) {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if (f == NULL) {
        printf("Erro ao alocar memória para a fila!\n");
        return NULL;
    }
    f->capacidade = capacidade;
    f->frente = 0;
    f->tras = -1;
    f->elementos = (int*)malloc(capacidade * sizeof(int));
    if (f->elementos == NULL) {
        printf("Erro ao alocar memória para os elementos da fila!\n");
        free(f);
        return NULL;
    }
    return f;
}

// Verifica se a fila está vazia
int fila_vazia(Fila* f) {
    return f->frente > f->tras;
}

// Verifica se a fila está cheia
int fila_cheia(Fila* f) {
    return f->tras == f->capacidade - 1;
}

// Enfileira um elemento
void enfileira(Fila* f, int valor) {
    if (fila_cheia(f)) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    f->elementos[++(f->tras)] = valor;
}

// Desenfileira um elemento
int desenfileira(Fila* f) {
    if (fila_vazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1; // Valor de erro
    }
    return f->elementos[f->frente++];
}

// Retorna o primeiro elemento da fila
int frente(Fila* f) {
    if (fila_vazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1; // Valor de erro
    }
    return f->elementos[f->frente];
}

// Exibe os elementos da fila
void exibe_fila(Fila* f) {
    if (fila_vazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Elementos da fila: ");
    for (int i = f->frente; i <= f->tras; i++) {
        printf("%d ", f->elementos[i]);
    }
    printf("\n");
}

// Libera a memória da fila
void libera_fila(Fila* f) {
    if (f != NULL) {
        free(f->elementos);
        free(f);
    }
}
