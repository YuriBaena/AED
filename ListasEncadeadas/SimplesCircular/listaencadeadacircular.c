#include <stdio.h>
#include <stdlib.h>
#include "listaencadeadacircular.h"

// Cria um novo nó
no* cria_no(int num) {
    no* novo = (no*)malloc(sizeof(no));
    if (!novo) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    novo->data = num;
    novo->prox = novo; // Aponta para ele mesmo na lista circular
    return novo;
}

// Insere no início da lista
void insere_no_inicio(no** lista, int num) {
    no* novo = cria_no(num);
    if (!novo) return;
    
    if (*lista == NULL) {
        *lista = novo;
        return;
    }
    
    no* temp = *lista;
    while (temp->prox != *lista) {
        temp = temp->prox;
    }
    
    novo->prox = *lista;
    temp->prox = novo;
    *lista = novo;
}

// Insere no fim da lista
void insere_no_fim(no** lista, int num) {
    no* novo = cria_no(num);
    if (!novo) return;
    
    if (*lista == NULL) {
        *lista = novo;
        return;
    }
    
    no* temp = *lista;
    while (temp->prox != *lista) {
        temp = temp->prox;
    }
    temp->prox = novo;
    novo->prox = *lista;
}

// Insere em ordem crescente
void insere_no_ordem(no** lista, int num) {
    no* novo = cria_no(num);
    if (!novo) return;
    
    if (*lista == NULL || (*lista)->data >= num) {
        insere_no_inicio(lista, num);
        return;
    }
    
    no* temp = *lista;
    while (temp->prox != *lista && temp->prox->data < num) {
        temp = temp->prox;
    }
    novo->prox = temp->prox;
    temp->prox = novo;
}

// Remove um nó da lista
void remove_no(no** lista, int target) {
    if (*lista == NULL) return;
    
    no* temp = *lista;
    no* prev = NULL;
    
    do {
        if (temp->data == target) {
            if (prev == NULL) { // Removendo o primeiro nó
                if (temp->prox == *lista) {
                    free(temp);
                    *lista = NULL;
                    return;
                }
                no* last = *lista;
                while (last->prox != *lista) {
                    last = last->prox;
                }
                *lista = temp->prox;
                last->prox = *lista;
                free(temp);
                return;
            } else {
                prev->prox = temp->prox;
                free(temp);
                return;
            }
        }
        prev = temp;
        temp = temp->prox;
    } while (temp != *lista);
}

// Busca um elemento na lista
void busca(no* lista, int target) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    no* temp = lista;
    do {
        if (temp->data == target) {
            printf("Elemento %d encontrado!\n", target);
            return;
        }
        temp = temp->prox;
    } while (temp != lista);
    
    printf("Elemento %d não encontrado.\n", target);
}

// Exibe a lista
void exibe(no* lista) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    no* temp = lista;
    do {
        printf("%d -> ", temp->data);
        temp = temp->prox;
    } while (temp != lista);
    printf("(volta ao início)\n");
}

// Libera toda a lista
void libera(no** lista) {
    if (*lista == NULL) return;
    
    no* temp = *lista;
    no* prox;
    
    do {
        prox = temp->prox;
        free(temp);
        temp = prox;
    } while (temp != *lista);
    
    *lista = NULL;
}
