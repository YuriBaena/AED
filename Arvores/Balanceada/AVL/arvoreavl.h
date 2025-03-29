#ifndef ARVOREAVL_H
#define ARVOREAVL_H

typedef struct no {
    int data;
    int altura;
    struct no* esquerda;
    struct no* direita;
} No;

// Funções para manipulação da árvore AVL
No* cria_no(int valor);
int altura(No* raiz);
int balanceamento(No* raiz);
No* rotacao_direita(No* raiz);
No* rotacao_esquerda(No* raiz);
No* rotacao_dupla_direita(No* raiz);
No* rotacao_dupla_esquerda(No* raiz);
No* insere(No* raiz, int valor);
No* busca(No* raiz, int valor);
void em_ordem(No* raiz);
void pre_ordem(No* raiz);
void pos_ordem(No* raiz);
No* remover(No* raiz, int valor);
No* minimo(No* raiz);
void libera(No* raiz);

#endif
