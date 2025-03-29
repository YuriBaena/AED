#include <stdio.h>
#include "arvoreRN.h"

int main() {
    No* raiz = NULL;

    // Inserir alguns elementos na árvore
    printf("Inserindo elementos na árvore Red-Black:\n");
    inserir_rb(&raiz, cria_no(30));
    inserir_rb(&raiz, cria_no(20));
    inserir_rb(&raiz, cria_no(40));
    inserir_rb(&raiz, cria_no(10));
    inserir_rb(&raiz, cria_no(25));
    inserir_rb(&raiz, cria_no(35));
    inserir_rb(&raiz, cria_no(50));

    // Exibir a árvore em ordem
    printf("Árvore em ordem (in-order): ");
    em_ordem(raiz);
    printf("\n");

    // Buscar um valor na árvore
    printf("Buscando o valor 25 na árvore:\n");
    No* encontrado = buscar(raiz, 25);
    if (encontrado != NULL) {
        printf("Elemento %d encontrado.\n", encontrado->data);
    } else {
        printf("Elemento não encontrado.\n");
    }

    // Liberação de memória
    liberar_arvore(raiz);

    return 0;
}
