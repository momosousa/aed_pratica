#include <stdio.h>
#include <stdlib.h>

#include "listaDuplamenteEncadeada.h"

int main() {
    // Criação da lista
    Lista *lista = criarLista();
    printf("Lista criada.\n\n");

    // Verifica se a lista está vazia e o tamanho inicial
    printf("Está vazia? %d\n\n", isEmpty(lista));
    printf("Tamanho inicial: %d\n\n", getSize(lista));

    // Teste de busca em lista vazia
    printf("Tentativa de busca (5) em lista vazia.\n");
    int pos = busca(lista, 5);
    printf("Posição retornada: %d\n\n", pos);

    // Inserções na lista
    printf("Inserindo 10 na head.\n");
    insertHead(lista, 10);
    printLista(lista);

    printf("\n\nInserindo 5 na head.\n");
    insertHead(lista, 5);
    printLista(lista);

    printf("\n\nInserindo 3 na tail.\n");
    insertTail(lista, 3);
    printLista(lista);

    printf("\n\nInserindo 8 na posição 2.\n");
    insert(lista, 8, 2);
    printLista(lista);

    printf("\n\nInserindo 9 na tail.\n");
    insertTail(lista, 9);
    printLista(lista);

    printf("\n\nInserindo 8 na head novamente.\n");
    insertHead(lista, 8);
    printLista(lista);

    printf("\n\nInserindo 7 na posição 4.\n");
    insert(lista, 7, 4);
    printLista(lista);

    // Busca de elementos
    printf("\n\nBuscando posição do elemento 9.\n");
    pos = busca(lista, 9);
    printf("Posição de 9: %d\n", pos);

    // Remoções
    printf("\nRemovendo o elemento da head.\n");
    removeHead(lista);
    printLista(lista);

    printf("\n\nRemovendo o elemento da tail.\n");
    removeTail(lista);
    printLista(lista);

    printf("\n\nRemovendo o elemento na posição 2.\n");
    removeNode(lista, 2);
    printLista(lista);

    // Ordenação
    printf("\n\nOrdenando a lista de maneira decrescente...\n");
    ordenar(lista);
    printLista(lista);

    // Limpeza da lista
    printf("\n\nLimpando a lista...\n");
    clear(lista);
    printLista(lista);

    // Estado final da lista
    printf("\n\nApós limpar, está vazia? %d\n", isEmpty(lista));
    printf("\nTamanho final: %d\n", getSize(lista));

    // Libera a memória alocada para a lista
    free(lista);

    return 0;
}
