#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Cria uma pilha com capacidade definida
Pilha* cria_pilha(int capacidade) {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro ao alocar memória para a pilha!\n");
        return NULL;
    }
    p->capacidade = capacidade;
    p->topo = -1;
    p->elementos = (int*)malloc(capacidade * sizeof(int));
    if (p->elementos == NULL) {
        printf("Erro ao alocar memória para os elementos da pilha!\n");
        free(p);
        return NULL;
    }
    return p;
}

// Verifica se a pilha está vazia
int pilha_vazia(Pilha* p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
int pilha_cheia(Pilha* p) {
    return p->topo == p->capacidade - 1;
}

// Empilha um elemento
void empilha(Pilha* p, int valor) {
    if (pilha_cheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->elementos[++(p->topo)] = valor;
}

// Desempilha um elemento
int desempilha(Pilha* p) {
    if (pilha_vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1; // Valor de erro
    }
    return p->elementos[(p->topo)--];
}

// Retorna o topo da pilha
int topo(Pilha* p) {
    if (pilha_vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1; // Valor de erro
    }
    return p->elementos[p->topo];
}

// Exibe os elementos da pilha
void exibe_pilha(Pilha* p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Elementos da pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->elementos[i]);
    }
    printf("\n");
}

// Libera a memória da pilha
void libera_pilha(Pilha* p) {
    if (p != NULL) {
        free(p->elementos);
        free(p);
    }
}
