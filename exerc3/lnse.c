#include <stdio.h>
#include "lnse.h"

// Inicializa a lista e a fila estática de posições vazias
void inicializar(ListaEstatica *lista) {
    lista->head = VAZIO;
    lista->tail = VAZIO;
    lista->tamanho = 0;
    lista->inicioFila = 0;
    lista->fimFila = MAX - 1;

    // Preenche a fila estática com todas as posições disponíveis
    for (int i = 0; i < MAX; i++) {
        lista->filaVazia[i] = i;
        lista->elementos[i].prox = VAZIO;
        lista->elementos[i].valor = 0;
    }
}

// Função auxiliar para desenfileirar índice da fila de posições vazias
int dequeue(ListaEstatica *lista) {
    if (lista->inicioFila > lista->fimFila) {
        return VAZIO;
    }
    return lista->filaVazia[lista->inicioFila++];
}

// Função auxiliar para enfileirar índice na fila de posições vazias
void enqueue(ListaEstatica *lista, int indice) {
    if (lista->fimFila < MAX - 1) {
        lista->filaVazia[++lista->fimFila] = indice;
    }
}

// Insere um valor x na posição i da lista
void inserir(ListaEstatica *lista, int x, int i) {
    if (lista->inicioFila > lista->fimFila) {
        printf("Lista cheia!\n");
        return;
    }
    if (i < 0 || i > lista->tamanho) {
        printf("Posicao invalida!\n");
        return;
    }

    int indice = dequeue(lista);
    lista->elementos[indice].valor = x;

    if (lista->head == VAZIO) { // Lista vazia
        lista->head = indice;
        lista->tail = indice;
        lista->elementos[indice].prox = VAZIO;
    } else if (i == 0) { // Inserir no início
        lista->elementos[indice].prox = lista->head;
        lista->head = indice;
    } else {
        int anterior = lista->head;
        for (int pos = 0; pos < i - 1; pos++) {
            anterior = lista->elementos[anterior].prox;
        }
        lista->elementos[indice].prox = lista->elementos[anterior].prox;
        lista->elementos[anterior].prox = indice;
        if (lista->elementos[indice].prox == VAZIO) {
            lista->tail = indice;
        }
    }
    lista->tamanho++;
}

// Remove o item na posição i da lista e retorna o valor
int remover(ListaEstatica *lista, int i) {
    if (lista->head == VAZIO) {
        printf("Lista vazia!\n");
        return VAZIO;
    }
    if (i < 0 || i >= lista->tamanho) {
        printf("Posicao invalida!\n");
        return VAZIO;
    }

    int anterior = VAZIO;
    int atual = lista->head;
    for (int pos = 0; pos < i; pos++) {
        anterior = atual;
        atual = lista->elementos[atual].prox;
    }

    int valorRemovido = lista->elementos[atual].valor;

    if (anterior == VAZIO) { // Removendo o primeiro elemento
        lista->head = lista->elementos[atual].prox;
    } else {
        lista->elementos[anterior].prox = lista->elementos[atual].prox;
    }

    if (lista->elementos[atual].prox == VAZIO) { // Removendo o último elemento
        lista->tail = anterior;
    }

    enqueue(lista, atual);
    lista->elementos[atual].prox = VAZIO;
    lista->elementos[atual].valor = 0;
    lista->tamanho--;

    return valorRemovido;
}

// Busca o item x na lista e retorna sua posição
int buscar(ListaEstatica *lista, int x) {
    int atual = lista->head;
    int pos = 0;
    while (atual != VAZIO) {
        if (lista->elementos[atual].valor == x) {
            return pos;
        }
        atual = lista->elementos[atual].prox;
        pos++;
    }
    return VAZIO; // Não encontrado
}

// Retorna o número de elementos na lista
int size(ListaEstatica *lista) {
    return lista->tamanho;
}

// Remove todos os elementos da lista
void clear(ListaEstatica *lista) {
    inicializar(lista);
}

// Imprime a lista real, o índice do head, o índice do tail e os valores no vetor
void imprimir(ListaEstatica *lista) {
    printf("Lista real: ");
    int atual = lista->head;
    while (atual != VAZIO) {
        printf("%d ", lista->elementos[atual].valor);
        atual = lista->elementos[atual].prox;
    }
    printf("\nHead: %d, Tail: %d\n", lista->head, lista->tail);
    printf("Vetor de elementos:\n");
    for (int i = 0; i < MAX; i++) {
        if (lista->elementos[i].prox != VAZIO || lista->elementos[i].valor != 0) {
            printf("indice %d: Valor = %d, Prox = %d\n", i, lista->elementos[i].valor, lista->elementos[i].prox);
        } else {
            printf("indice %d: (-)\n", i);
        }
    }
}


