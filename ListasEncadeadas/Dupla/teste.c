#include <stdio.h>
#include "listaencadeadaduplamente.h"

int main() {
    no* lista = NULL;

    // Testando inserção no início
    printf("Inserindo no início:\n");
    insere_no_inicio(&lista, 10);
    insere_no_inicio(&lista, 5);
    exibe(lista);

    // Testando inserção no fim
    printf("\nInserindo no fim:\n");
    insere_no_fim(&lista, 20);
    insere_no_fim(&lista, 25);
    exibe(lista);

    // Testando inserção ordenada
    printf("\nInserindo em ordem:\n");
    insere_no_ordem(&lista, 15);
    insere_no_ordem(&lista, 8);
    insere_no_ordem(&lista, 30);
    exibe(lista);

    // Testando busca
    printf("\nBuscando elementos:\n");
    busca(lista, 15);
    busca(lista, 100);

    // Testando remoção
    printf("\nRemovendo elementos:\n");
    remove_no(&lista, 10);
    remove_no(&lista, 30);
    remove_no(&lista, 5);
    exibe(lista);

    // Liberando a lista
    libera(&lista);
    printf("\nLista após liberar:\n");
    exibe(lista);

    return 0;
}
