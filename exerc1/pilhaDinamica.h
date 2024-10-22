#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

#include <stdio.h>
#include <stdlib.h>
#include "fila_estaticaCircular.h"
#include "fila_estaticaCircular.c"

// Definição do nó da pilha
typedef struct Node {
    char data;
    struct Node* next; // Usando struct antes de Node* porque o alias ainda não foi criado (está na linha abaixo)
} Node;

// Definição da pilha dinâmica
typedef struct {
    Node* top;
    int tamanho;
} Pilha;

// Função para criar um novo nó
Node* criarNode(char data);

// Função para verificar se a pilha está vazia
int isEmpty(Pilha* pilha);

// Função para adicionar um elemento no topo da pilha
void push(Pilha* pilha, char data);

// Função para remover e retornar o elemento do topo da pilha
char pop(Pilha* pilha);

// Função para retornar a quantidade de elementos da pilha
int size(Pilha* pilha);

// Função para retornar o topo da pilha sem remover
char getTop(Pilha* pilha);

// Função para limpar a pilha
void clear(Pilha* pilha);

// Função para imprimir a pilha
void imprimirPilha(Pilha* pilha);

#endif // PILHADINAMICA_H
