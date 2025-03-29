# Estruturas de Dados em C

Este repositório contém implementações de diversas **estruturas de dados** fundamentais em **C**, com o objetivo de proporcionar uma compreensão profunda de como essas estruturas funcionam internamente e como manipulá-las de maneira eficiente.

## Estruturas Implementadas

O repositório inclui implementações de várias estruturas de dados e suas respectivas operações básicas:

- **Listas Encadeadas**
  - Simples
  - Duplamente Encadeada
  - Circular
- **Pilha (Stack)**
- **Fila (Queue)**
- **Árvore Binária de Busca (BST)**
- **Árvore Balanceada**
  - Árvore Red-Black
  - Árvore AVL
- **Heap**
  - Min-Heap
  - Max-Heap
- **Tabelas de Hash**
  
Além das implementações básicas, o repositório também inclui algoritmos de balanceamento para árvores (como rotação em árvores binárias e balanceamento de árvores Red-Black e AVL), além de outras operações importantes para cada estrutura de dados.

## Funcionalidades

Cada estrutura de dados possui as seguintes operações básicas:

- **Inserção**: Adicionar elementos à estrutura.
- **Remoção**: Remover elementos da estrutura.
- **Busca**: Procurar elementos na estrutura.
- **Exibição**: Mostrar os elementos da estrutura em diferentes ordens (por exemplo, in-order para árvores).
- **Liberação de memória**: Liberação de todos os nós e elementos alocados dinamicamente.

As árvores balanceadas, como as **Red-Black** e **AVL**, têm operações adicionais para garantir o balanceamento após inserções e remoções, o que garante uma complexidade de tempo eficiente para operações de busca.

## Testes e Exemplos

O repositório também contém exemplos de uso e testes unitários para cada estrutura de dados. Os testes são projetados para verificar a corretude das operações implementadas e demonstrar como utilizá-las.

### Como Usar

Para testar as estruturas de dados e seus algoritmos, basta compilar os arquivos de código-fonte com um compilador C, como o `gcc`:

```bash
gcc nome_do_arquivo.c -o programa
./programa
