#include <stdio.h>
#include <stdlib.h>

#include "fila_estaticaCircular.h"


// Função para inicializar a fila
Fila* criarFila(int capacity) {

    Fila *fila = (Fila *)malloc(sizeof(Fila));

    fila->capacity = capacity;

    // cria o vetor que guardara os dados de maneira dinamica
    fila->data = (char *)malloc(capacity * sizeof(char));

    fila->front = -1;
    fila->rear = -1;
    fila->size = 0;
}

// Função para obter o tamanho da fila
int getSize(Fila *fila) {
    return fila->size;

    // Outras maneiras de fazer a mesma coisa
    // --------------------------------------
    // return fila->size == fila->capacity;

    // if (fila->size == fila->capacity){
    //    return 1;
    // }
    // else{
    //    return 0;
    // }
}

// Função para verificar se a fila está vazia
int isEmpty(Fila *fila) {
    return fila->size == 0;
}

// Função para verificar se a fila está cheia
int isFull(Fila *fila) {
    return fila->size == fila->capacity;
}

// Função para adicionar um elemento na fila
void enqueue(Fila *fila, char data) {
    if (fila->size >= fila->capacity) {
        printf("Erro. Overflow!");
        return;
    }

    if (fila->front == -1) {
        fila->front = 0;
        fila->rear = 0;
    } else if (fila->rear == fila->capacity - 1) {
        fila->rear = 0;
    } else {
        fila->rear = fila->rear + 1;
    }

    fila->data[fila->rear] = data;
    fila->size += 1;
}

// Função para remover um elemento da fila
char dequeue(Fila *fila) {
    if (fila->size == 0) {
        printf("Erro. Underflow!");
        return '0';
    }

    char temp = fila->data[fila->front];

    if (fila->size == 1) {
        fila->front = -1;
        fila->rear = -1;
    } else if (fila->front == fila->capacity - 1) {
        fila->front = 0;
    } else {
        fila->front = fila->front + 1;
    }

    fila->size -= 1;
    return temp;
}

// Função para obter o primeiro elemento da fila
char getFront(Fila *fila) {
    if (isEmpty(fila)) {
        printf("Fila vazia\n");
        return '0';
    }

    return fila->data[fila->front];
}

// Função para limpar a fila
void clear(Fila *fila) {
    fila->front = -1;
    fila->rear = -1;
    fila->size = 0;
}

// Função para imprimir a fila
void imprimir(Fila *fila) {

    if (isEmpty(fila)) {
        printf(" Fila vazia!\n");
        return;
    }

    Fila* auxFila = criarFila(fila->capacity);

    printf("");
    // Seguindo as regras da fila, a unica forma de
    // acessar todos os seus valores, eh destruindo ela
    while( isEmpty(fila)!=1 ){
        int front = dequeue(fila);

        // Salva na fila auxiliar para recuperar depois
        enqueue(auxFila, front);

        printf(" %c", front);
    }
    printf("");

    // Recupera a fila
    while( isEmpty(auxFila)!=1 ){
        int auxValor = dequeue(auxFila);

        // Recupera o valor na fila principal
        enqueue(fila, auxValor);
    }

    free(auxFila);
}
