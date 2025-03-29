#include <stdio.h>
#include <stdlib.h>
#include "listaencadeadaduplamentecircular.h"

// Cria um novo nó
no* cria_no(int num) {
    no* novo = (no*)malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    novo->data = num;
    novo->prox = novo;  // Aponta para ele mesmo (circular)
    novo->ant = novo;   // Aponta para ele mesmo (circular)
    return novo;
}

// Insere no início da lista
void insere_no_inicio(no** lista, int num) {
    no* novo = cria_no(num);
    if (*lista == NULL) {
        *lista = novo;
    } else {
        no* temp = *lista;
        novo->prox = temp;
        novo->ant = temp->ant;
        temp->ant->prox = novo;
        temp->ant = novo;
        *lista = novo;
    }
}

// Insere no fim da lista
void insere_no_fim(no** lista, int num) {
    no* novo = cria_no(num);
    if (*lista == NULL) {
        *lista = novo;
    } else {
        no* temp = *lista;
        while (temp->prox != *lista) {
            temp = temp->prox;
        }
        temp->prox = novo;
        novo->ant = temp;
        novo->prox = *lista;
        (*lista)->ant = novo;
    }
}

// Insere na ordem
void insere_no_ordem(no** lista, int num) {
    no* novo = cria_no(num);
    if (*lista == NULL) {
        *lista = novo;
    } else {
        no* temp = *lista;
        while (temp->prox != *lista && temp->data < num) {
            temp = temp->prox;
        }
        if (temp->data >= num) {
            novo->prox = temp;
            novo->ant = temp->ant;
            temp->ant->prox = novo;
            temp->ant = novo;
            if (temp == *lista) {
                *lista = novo;
            }
        } else {
            insere_no_fim(lista, num);
        }
    }
}

// Remove um nó da lista
void remove_no(no** lista, int target) {
    if (*lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    no* temp = *lista;
    do {
        if (temp->data == target) {
            if (temp == *lista) {
                if (temp->prox == *lista) {
                    *lista = NULL;
                } else {
                    *lista = temp->prox;
                    (*lista)->ant = temp->ant;
                    temp->ant->prox = *lista;
                }
            } else {
                temp->ant->prox = temp->prox;
                temp->prox->ant = temp->ant;
            }
            free(temp);
            return;
        }
        temp = temp->prox;
    } while (temp != *lista);
    printf("Elemento não encontrado!\n");
}

// Busca por um nó
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
    printf("Elemento %d não encontrado!\n", target);
}

// Exibe a lista
void exibe(no* lista) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    no* temp = lista;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prox;
    } while (temp != lista);
    printf("(volta para o início)\n");
}

// Libera a memória da lista
void libera(no** lista) {
    if (*lista == NULL) {
        return;
    }
    no* temp = *lista;
    do {
        no* prox = temp->prox;
        free(temp);
        temp = prox;
    } while (temp != *lista);
    *lista = NULL;
}
