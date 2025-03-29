#include <stdio.h>
#include <stdlib.h>
#include "arvoreRN.h"

// Função para criar um novo nó
No* cria_no(int data) {
    No* novo = (No*)malloc(sizeof(No));
    novo->data = data;
    novo->cor = RED; // O nó recém inserido é sempre vermelho
    novo->pai = NULL;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    return novo;
}

// Rotação à esquerda
void rotacao_esquerda(No** raiz, No* x) {
    No* y = x->direito;
    x->direito = y->esquerdo;
    if (y->esquerdo != NULL) {
        y->esquerdo->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == NULL) {
        *raiz = y;
    } else if (x == x->pai->esquerdo) {
        x->pai->esquerdo = y;
    } else {
        x->pai->direito = y;
    }
    y->esquerdo = x;
    x->pai = y;
}

// Rotação à direita
void rotacao_direita(No** raiz, No* x) {
    No* y = x->esquerdo;
    x->esquerdo = y->direito;
    if (y->direito != NULL) {
        y->direito->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == NULL) {
        *raiz = y;
    } else if (x == x->pai->direito) {
        x->pai->direito = y;
    } else {
        x->pai->esquerdo = y;
    }
    y->direito = x;
    x->pai = y;
}

// Balanceamento após inserção
void balancear_rb(No** raiz, No* z) {
    while (z->pai != NULL && z->pai->cor == RED) {
        if (z->pai == z->pai->pai->esquerdo) {
            No* y = z->pai->pai->direito;
            if (y != NULL && y->cor == RED) {
                z->pai->cor = BLACK;
                y->cor = BLACK;
                z->pai->pai->cor = RED;
                z = z->pai->pai;
            } else {
                if (z == z->pai->direito) {
                    z = z->pai;
                    rotacao_esquerda(raiz, z);
                }
                z->pai->cor = BLACK;
                z->pai->pai->cor = RED;
                rotacao_direita(raiz, z->pai->pai);
            }
        } else {
            No* y = z->pai->pai->esquerdo;
            if (y != NULL && y->cor == RED) {
                z->pai->cor = BLACK;
                y->cor = BLACK;
                z->pai->pai->cor = RED;
                z = z->pai->pai;
            } else {
                if (z == z->pai->esquerdo) {
                    z = z->pai;
                    rotacao_direita(raiz, z);
                }
                z->pai->cor = BLACK;
                z->pai->pai->cor = RED;
                rotacao_esquerda(raiz, z->pai->pai);
            }
        }
    }
    (*raiz)->cor = BLACK;
}

// Inserção na árvore Red-Black
void inserir_rb(No** raiz, No* z) {
    No* y = NULL;
    No* x = *raiz;
    while (x != NULL) {
        y = x;
        if (z->data < x->data) {
            x = x->esquerdo;
        } else {
            x = x->direito;
        }
    }
    z->pai = y;
    if (y == NULL) {
        *raiz = z;
    } else if (z->data < y->data) {
        y->esquerdo = z;
    } else {
        y->direito = z;
    }
    balancear_rb(raiz, z);
}

// Busca na árvore
No* buscar(No* raiz, int data) {
    while (raiz != NULL && data != raiz->data) {
        if (data < raiz->data) {
            raiz = raiz->esquerdo;
        } else {
            raiz = raiz->direito;
        }
    }
    return raiz;
}

// Exibição em ordem (in-order traversal)
void em_ordem(No* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerdo);
        printf("%d ", raiz->data);
        em_ordem(raiz->direito);
    }
}

// Libera a memória
void liberar_arvore(No* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esquerdo);
        liberar_arvore(raiz->direito);
        free(raiz);
    }
}
