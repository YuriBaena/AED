#ifndef PILHA_H
#define PILHA_H

typedef struct pilha {
    int topo;
    int capacidade;
    int* elementos;
} Pilha;

// Funções para manipulação da pilha
Pilha* cria_pilha(int capacidade);
int pilha_vazia(Pilha* p);
int pilha_cheia(Pilha* p);
void empilha(Pilha* p, int valor);
int desempilha(Pilha* p);
int topo(Pilha* p);
void exibe_pilha(Pilha* p);
void libera_pilha(Pilha* p);

#endif
