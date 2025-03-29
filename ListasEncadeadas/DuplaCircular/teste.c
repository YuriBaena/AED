#include <stdio.h>
#include "listaencadeadaduplamentecircular.h"

int main() {
    no* lista = NULL;

    // Inserindo elementos
    insere_no_inicio(&lista, 10);
    insere_no_inicio(&lista, 20);
    insere_no_fim(&lista, 5);
    insere_no_ordem(&lista, 15);
    insere_no_ordem(&lista, 25);

    // Exibindo a lista
    printf("Lista após inserções:\n");
    exibe(lista);

    // Buscando elementos
    busca(lista, 15);
    busca(lista, 100);

    // Removendo elementos
    printf("Removendo o elemento 15:\n");
    remove_no(&lista, 15);
    exibe(lista);

    printf("Removendo o elemento 100 (não existe):\n");
    remove_no(&lista, 100);
    exibe(lista);

    // Liberando memória
    libera(&lista);

    return 0;
}
