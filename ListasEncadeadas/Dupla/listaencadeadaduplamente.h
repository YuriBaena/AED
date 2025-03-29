#ifndef LISTAENCADEADADUPLAMENTE_H
#define LISTAENCADEADADUPLAMENTE_H

typedef struct no{
	int data;
	struct no* prox;
	struct no* ant;
}no;

no* cria_no(int num);
void insere_no_inicio(no** lista, int num);
void insere_no_fim(no** lista, int num);
void insere_no_ordem(no** lista, int num);
void remove_no(no** lista, int target);
void busca(no* lista, int target);
void exibe(no* lista);
void libera(no** lista);

#endif