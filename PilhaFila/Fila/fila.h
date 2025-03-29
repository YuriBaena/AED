#ifndef FILA_H
#define FILA_H

typedef struct fila {
    int frente, tras, capacidade;
    int* elementos;
} Fila;

// Funções para manipulação da fila
Fila* cria_fila(int capacidade);
int fila_vazia(Fila* f);
int fila_cheia(Fila* f);
void enfileira(Fila* f, int valor);
int desenfileira(Fila* f);
int frente(Fila* f);
void exibe_fila(Fila* f);
void libera_fila(Fila* f);

#endif
