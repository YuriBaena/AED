#include <stdio.h>
#include "fila.h"

int main() {
    // Criando a fila
    Fila* f = cria_fila(5);

    // Enfileirando elementos
    enfileira(f, 10);
    enfileira(f, 20);
    enfileira(f, 30);
    enfileira(f, 40);
    enfileira(f, 50);

    // Exibindo a fila
    printf("Fila após enfileiramentos:\n");
    exibe_fila(f);

    // Tentando enfileirar quando a fila estiver cheia
    enfileira(f, 60);

    // Desenfileirando elementos
    printf("Elemento desenfileirado: %d\n", desenfileira(f));
    printf("Elemento desenfileirado: %d\n", desenfileira(f));

    // Exibindo a fila após os desenfileiramentos
    printf("Fila após desenfileiramentos:\n");
    exibe_fila(f);

    // Verificando a frente da fila
    printf("Elemento da frente da fila: %d\n", frente(f));

    // Liberando a fila
    libera_fila(f);

    return 0;
}
