#include <stdio.h>
#include "arvorebinaria.h"

int main() {
    No* raiz = NULL;

    // Inserindo elementos na árvore
    raiz = insere(raiz, 50);
    raiz = insere(raiz, 30);
    raiz = insere(raiz, 20);
    raiz = insere(raiz, 40);
    raiz = insere(raiz, 70);
    raiz = insere(raiz, 60);
    raiz = insere(raiz, 80);

    // Exibindo a árvore em diferentes ordens
    printf("Em ordem: ");
    em_ordem(raiz);
    printf("\n");

    printf("Pré-ordem: ");
    pre_ordem(raiz);
    printf("\n");

    printf("Pós-ordem: ");
    pos_ordem(raiz);
    printf("\n");

    // Buscando um valor na árvore
    No* encontrado = busca(raiz, 40);
    if (encontrado != NULL) {
        printf("Elemento %d encontrado na árvore.\n", encontrado->data);
    } else {
        printf("Elemento não encontrado.\n");
    }

    // Removendo um valor da árvore
    printf("Removendo o valor 20 da árvore:\n");
    raiz = remover(raiz, 20);

    // Exibindo a árvore após a remoção
    printf("Em ordem após remoção: ");
    em_ordem(raiz);
    printf("\n");

    // Liberando a memória da árvore
    libera(raiz);

    return 0;
}
