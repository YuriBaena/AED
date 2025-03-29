#include <stdio.h>
#include "pilha.h"

int main() {
    // Criando a pilha
    Pilha* p = cria_pilha(5);

    // Empilhando elementos
    empilha(p, 10);
    empilha(p, 20);
    empilha(p, 30);
    empilha(p, 40);
    empilha(p, 50);

    // Exibindo a pilha
    printf("Pilha após empilhamentos:\n");
    exibe_pilha(p);

    // Tentando empilhar quando a pilha estiver cheia
    empilha(p, 60);

    // Desempilhando elementos
    printf("Elemento desempilhado: %d\n", desempilha(p));
    printf("Elemento desempilhado: %d\n", desempilha(p));

    // Exibindo a pilha após os desempilhamentos
    printf("Pilha após desempilhamentos:\n");
    exibe_pilha(p);

    // Verificando o topo
    printf("Topo da pilha: %d\n", topo(p));

    // Liberando a pilha
    libera_pilha(p);

    return 0;
}
