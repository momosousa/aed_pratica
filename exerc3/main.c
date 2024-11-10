#include <stdio.h>
#include "lnse.h"
#include "lnse.c" /*no meu Visual Code só roda se acrescentar o arquivo .c também, caso não 
rodar, retire esse .c*/

int main() {
    ListaEstatica lista;
    inicializar(&lista);

    // Inserindo elementos na lista
    inserir(&lista, 10, 0); // Inserir na posição 0
    inserir(&lista, 20, 1); // Inserir na posição 1
    inserir(&lista, 30, 2); // Inserir na posição 2
    inserir(&lista, 40, 3); // Inserir na posição 3
    inserir(&lista, 50, 4); // Inserir na posição 4

    // Imprimindo a lista
    imprimir(&lista);

    // Buscando um elemento na lista
    int valorBusca = 30;
    int posicao = buscar(&lista, valorBusca);
    if (posicao != VAZIO) {
        printf("Elemento %d encontrado na posicao: %d\n", valorBusca, posicao);
    } else {
        printf("Elemento %d nao encontrado na lista.\n", valorBusca);
    }

    // Removendo um elemento da lista
    int valorRemovido = remover(&lista, posicao);
    if (valorRemovido != VAZIO) {
        printf("Elemento %d removido da lista.\n", valorRemovido);
    }

    // Imprimindo a lista após remoção
    imprimir(&lista);

    // Tamanho da lista
    printf("Tamanho atual da lista: %d\n", size(&lista));

    // Limpando a lista
    clear(&lista);
    printf("Lista apos limpar:\n");
    imprimir(&lista);

    return 0;
}

