#include <stdio.h>
#include <stdlib.h>
#include "arvoreavl.h"

// Cria um novo nó com o valor especificado
No* cria_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória para o nó!\n");
        return NULL;
    }
    novo->data = valor;
    novo->altura = 1;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// Retorna a altura de um nó
int altura(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return raiz->altura;
}

// Calcula o fator de balanceamento de um nó
int balanceamento(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return altura(raiz->esquerda) - altura(raiz->direita);
}

// Rotação simples à direita
No* rotacao_direita(No* raiz) {
    No* nova_raiz = raiz->esquerda;
    No* temp = nova_raiz->direita;

    nova_raiz->direita = raiz;
    raiz->esquerda = temp;

    raiz->altura = 1 + (altura(raiz->esquerda) > altura(raiz->direita) ? altura(raiz->esquerda) : altura(raiz->direita));
    nova_raiz->altura = 1 + (altura(nova_raiz->esquerda) > altura(nova_raiz->direita) ? altura(nova_raiz->esquerda) : altura(nova_raiz->direita));

    return nova_raiz;
}

// Rotação simples à esquerda
No* rotacao_esquerda(No* raiz) {
    No* nova_raiz = raiz->direita;
    No* temp = nova_raiz->esquerda;

    nova_raiz->esquerda = raiz;
    raiz->direita = temp;

    raiz->altura = 1 + (altura(raiz->esquerda) > altura(raiz->direita) ? altura(raiz->esquerda) : altura(raiz->direita));
    nova_raiz->altura = 1 + (altura(nova_raiz->esquerda) > altura(nova_raiz->direita) ? altura(nova_raiz->esquerda) : altura(nova_raiz->direita));

    return nova_raiz;
}

// Rotação dupla à direita (primeiro esquerda, depois direita)
No* rotacao_dupla_direita(No* raiz) {
    raiz->esquerda = rotacao_esquerda(raiz->esquerda);
    return rotacao_direita(raiz);
}

// Rotação dupla à esquerda (primeiro direita, depois esquerda)
No* rotacao_dupla_esquerda(No* raiz) {
    raiz->direita = rotacao_direita(raiz->direita);
    return rotacao_esquerda(raiz);
}

// Insere um valor na árvore AVL e realiza as rotações necessárias
No* insere(No* raiz, int valor) {
    if (raiz == NULL) {
        return cria_no(valor);
    }

    if (valor < raiz->data) {
        raiz->esquerda = insere(raiz->esquerda, valor);
    } else if (valor > raiz->data) {
        raiz->direita = insere(raiz->direita, valor);
    } else {
        return raiz;  // Valores duplicados não são permitidos
    }

    raiz->altura = 1 + (altura(raiz->esquerda) > altura(raiz->direita) ? altura(raiz->esquerda) : altura(raiz->direita));

    int bal = balanceamento(raiz);

    // Caso 1: Rotação simples à direita
    if (bal > 1 && valor < raiz->esquerda->data) {
        return rotacao_direita(raiz);
    }

    // Caso 2: Rotação simples à esquerda
    if (bal < -1 && valor > raiz->direita->data) {
        return rotacao_esquerda(raiz);
    }

    // Caso 3: Rotação dupla à direita
    if (bal > 1 && valor > raiz->esquerda->data) {
        return rotacao_dupla_direita(raiz);
    }

    // Caso 4: Rotação dupla à esquerda
    if (bal < -1 && valor < raiz->direita->data) {
        return rotacao_dupla_esquerda(raiz);
    }

    return raiz;
}

// Busca um valor na árvore AVL
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

// Remove um nó da árvore AVL
No* remover(No* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->data) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->data) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            No* temp = raiz->esquerda ? raiz->esquerda : raiz->direita;
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else {
                *raiz = *temp;
            }
            free(temp);
        } else {
            No* temp = minimo(raiz->direita);
            raiz->data = temp->data;
            raiz->direita = remover(raiz->direita, temp->data);
        }
    }

    if (raiz == NULL) {
        return raiz;
    }

    raiz->altura = 1 + (altura(raiz->esquerda) > altura(raiz->direita) ? altura(raiz->esquerda) : altura(raiz->direita));

    int bal = balanceamento(raiz);

    if (bal > 1 && balanceamento(raiz->esquerda) >= 0) {
        return rotacao_direita(raiz);
    }
    if (bal > 1 && balanceamento(raiz->esquerda) < 0) {
        return rotacao_dupla_direita(raiz);
    }
    if (bal < -1 && balanceamento(raiz->direita) <= 0) {
        return rotacao_esquerda(raiz);
    }
    if (bal < -1 && balanceamento(raiz->direita) > 0) {
        return rotacao_dupla_esquerda(raiz);
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

// Libera a memória da árvore AVL
void libera(No* raiz) {
    if (raiz != NULL) {
        libera(raiz->esquerda);
        libera(raiz->direita);
        free(raiz);
    }
}
