#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.h"

// Cria um novo nó com o valor especificado
No* cria_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória para o nó!\n");
        return NULL;
    }
    novo->data = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// Insere um valor na árvore binária
No* insere(No* raiz, int valor) {
    if (raiz == NULL) {
        return cria_no(valor);
    }
    if (valor < raiz->data) {
        raiz->esquerda = insere(raiz->esquerda, valor);
    } else if (valor > raiz->data) {
        raiz->direita = insere(raiz->direita, valor);
    }
    return raiz;
}

// Busca um valor na árvore binária
No* busca(No* raiz, int valor) {
    if (raiz == NULL || raiz->data == valor) {
        return raiz;
    }
    if (valor < raiz->data) {
        return busca(raiz->esquerda, valor);
    }
    return busca(raiz->direita, valor);
}

// Traversal em ordem (esquerda, raiz, direita)
void em_ordem(No* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->data);
        em_ordem(raiz->direita);
    }
}

// Traversal pré-ordem (raiz, esquerda, direita)
void pre_ordem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->data);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

// Traversal pós-ordem (esquerda, direita, raiz)
void pos_ordem(No* raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->data);
    }
}

// Remove um nó com o valor especificado
No* remover(No* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }
    if (valor < raiz->data) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->data) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        No* temp = minimo(raiz->direita);
        raiz->data = temp->data;
        raiz->direita = remover(raiz->direita, temp->data);
    }
    return raiz;
}

// Encontra o nó com o valor mínimo
No* minimo(No* raiz) {
    No* atual = raiz;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

// Libera a memória da árvore binária
void libera(No* raiz) {
    if (raiz != NULL) {
        libera(raiz->esquerda);
        libera(raiz->direita);
        free(raiz);
    }
}
