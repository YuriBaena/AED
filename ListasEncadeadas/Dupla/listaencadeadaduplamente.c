#include <stdio.h>
#include <stdlib.h>
#include "listaencadeadaduplamente.h"

// Cria um novo nó
no* cria_no(int num) {
    no* novo = (no*)malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    novo->data = num;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

// Insere no início da lista
void insere_no_inicio(no** lista, int num) {
    no* novo = cria_no(num);
    if (!novo) return;
    
    if (*lista != NULL) {
        novo->prox = *lista;
        (*lista)->ant = novo;
    }
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
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novo;
    novo->ant = temp;
}

// Insere em ordem crescente
void insere_no_ordem(no** lista, int num) {
    no* novo = cria_no(num);
    if (!novo) return;
    
    if (*lista == NULL || (*lista)->data >= num) {
        novo->prox = *lista;
        if (*lista != NULL) (*lista)->ant = novo;
        *lista = novo;
        return;
    }
    
    no* temp = *lista;
    while (temp->prox != NULL && temp->prox->data < num) {
        temp = temp->prox;
    }
    novo->prox = temp->prox;
    if (temp->prox != NULL) temp->prox->ant = novo;
    temp->prox = novo;
    novo->ant = temp;
}

// Remove um nó da lista
void remove_no(no** lista, int target) {
    if (*lista == NULL) return;
    
    no* temp = *lista;
    while (temp != NULL && temp->data != target) {
        temp = temp->prox;
    }
    
    if (temp == NULL) return;
    
    if (temp->ant != NULL) temp->ant->prox = temp->prox;
    else *lista = temp->prox;
    
    if (temp->prox != NULL) temp->prox->ant = temp->ant;
    
    free(temp);
}

// Busca um elemento na lista
void busca(no* lista, int target) {
    no* temp = lista;
    while (temp != NULL) {
        if (temp->data == target) {
            printf("Elemento %d encontrado!\n", target);
            return;
        }
        temp = temp->prox;
    }
    printf("Elemento %d não encontrado.\n", target);
}

// Exibe a lista
void exibe(no* lista) {
    no* temp = lista;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prox;
    }
    printf("NULL\n");
}

// Libera toda a lista
void libera(no** lista) {
    no* temp;
    while (*lista) {
        temp = *lista;
        *lista = (*lista)->prox;
        free(temp);
    }
}
