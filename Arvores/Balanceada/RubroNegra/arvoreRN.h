#ifndef ARVORERN_H
#define ARVORERN_H

typedef enum { RED, BLACK } cor;

typedef struct no {
    int data;
    cor cor; // A cor do nó
    struct no* pai; // Ponteiro para o nó pai
    struct no* esquerdo; // Ponteiro para o nó esquerdo
    struct no* direito; // Ponteiro para o nó direito
} No;

// Funções básicas
No* cria_no(int data);
void rotacao_esquerda(No** raiz, No* x);
void rotacao_direita(No** raiz, No* x);
void inserir_rb(No** raiz, No* z);
void balancear_rb(No** raiz, No* z);
No* buscar(No* raiz, int data);
void liberar_arvore(No* raiz);
void em_ordem(No* raiz);

#endif
