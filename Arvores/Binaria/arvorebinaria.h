#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

typedef struct no {
    int data;
    struct no* esquerda;
    struct no* direita;
} No;

// Funções para manipulação da árvore binária
No* cria_no(int valor);
No* insere(No* raiz, int valor);
No* busca(No* raiz, int valor);
void em_ordem(No* raiz);
void pre_ordem(No* raiz);
void pos_ordem(No* raiz);
No* remover(No* raiz, int valor);
No* minimo(No* raiz);
void libera(No* raiz);

#endif
