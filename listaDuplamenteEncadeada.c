#include "listaDuplamenteEncadeada.h"

#include <stdio.h>
#include <stdlib.h>

// Função para criar um novo nó
Node *criarNode(int data) {
  Node *novoNode = (Node *)malloc(sizeof(Node));
  if (novoNode == NULL) {
    printf("Erro ao alocar memoria!\n");
    exit(1);
  }
  novoNode->data = data;
  novoNode->next = NULL;
  novoNode->prev = NULL;
  return novoNode;
}

// Função para inicializar uma lista duplamente ligada
Lista *criarLista() {
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  if (lista == NULL) {
    printf("Erro ao alocar memoria!\n");
    exit(1);
  }
  lista->head = NULL;
  lista->tail = NULL;
  lista->size = 0;
  lista->ordenado = 0;
  return lista;
}

int getSize(Lista *lista) { return lista->size; }

int isEmpty(Lista *lista) {
  return getSize(lista) == 0;

  // return lista->head == NULL
}

void insertHead(Lista *lista, int data) {

  Node *newNode = criarNode(data);

  if (getSize(lista) == 0) {
    lista->head = newNode;
    lista->tail = newNode;
  } else {
    newNode->next = lista->head;
    lista->head->prev = newNode;
    lista->head = newNode;
  }

  lista->size++;
  lista->ordenado = 0;
}

void insertTail(Lista *lista, int data) {

  if (isEmpty(lista)) {
    insertHead(lista, data);
  } else {
    Node *newNode = criarNode(data);

    newNode->prev = lista->tail;
    lista->tail->next = newNode;

    lista->tail = newNode;

    lista->size++;
    lista->ordenado = 0;
  }
}

void insert(Lista *lista, int data, int position) {

  if (position <= getSize(lista)) {

    if (position == 0) {
      insertHead(lista, data);
    } else if (position == getSize(lista)) {
      insertTail(lista, data);
    } else {

      Node *newNode = criarNode(data);

      Node *auxNode = lista->head;
      for (int i = 0; i < position - 1; i++) {
        auxNode = auxNode->next;
      }

      newNode->prev = auxNode;
      newNode->next = auxNode->next;

      auxNode->next->prev = newNode;
      auxNode->next = newNode;

      lista->size++;
      lista->ordenado = 0;
    }
  }
}

// Função para remover um elemento da lista
void removeHead(Lista *lista) {

  if (isEmpty(lista)) {
    printf("Erro. Underflow!");
    return;
  }

  Node *nodeRemover = lista->head;

  if (getSize(lista) == 1) {
    lista->tail = NULL;
    lista->head = NULL;
  } else {
    lista->head = nodeRemover->next;
    lista->head->prev = NULL;
  }

  lista->size--;

  free(nodeRemover);
}

void removeTail(Lista *lista) {

  if (isEmpty(lista)) {
    printf("Erro. Underflow!");
    return;
  }

  Node *nodeRemover = lista->tail;

  if (getSize(lista) == 1) {
    lista->tail = NULL;
    lista->head = NULL;
  } else {
    lista->tail = nodeRemover->prev;
    lista->tail->next = NULL;
  }

  lista->size--;

  free(nodeRemover); // limpa o ponteiro da memória
}

void removeNode(Lista *lista, int position) {

  if (isEmpty(lista)) {
    printf("Erro. Underflow!");
    return;
  }

  if ((position < 0) || (position >= getSize(lista))) {
    printf("Posição inválida!");
    return;
  }

  // se é o primeiro nó
  if (position == 0) {
    removeHead(lista);
    return;
  }

  // se é o último nó
  if (position == getSize(lista) - 1) {
    removeTail(lista);
    return;
  }

  Node *tempNode = lista->head;
  int i = 0;
  while (tempNode != NULL) {

    if (i == position) {

      tempNode->prev->next = tempNode->next;

      tempNode->next->prev = tempNode->prev;

      break;
    }

    tempNode = tempNode->next;
    i++;
  }

  lista->size--;
  free(tempNode);
}

void clear(Lista *lista) {
  Node *tempNode = lista->head;
  // int tamanho = getSize(lista);
  // for(int i=0; i<tamanho; i++){
  //     removeHead(lista);
  // }

  while (getSize(lista) > 0) {
    removeHead(lista);
  }
}

void printLista(Lista *lista) {
  Node *nodeAtual = lista->head;

  if (getSize(lista) == 0) {
    printf("\n[]");
    return;
  }

  printf("\n[");
  while (nodeAtual->next != NULL) {
    printf(" %d ", nodeAtual->data);
    nodeAtual = nodeAtual->next;
  }

  // imprime o último noh
  printf(" %d ", nodeAtual->data);

  printf("]");
}

int busca(Lista *lista, int data) {

  Node *tempNode = lista->head;
  if (lista->ordenado == 0) {
    for (int i = 0; i < getSize(lista); i++) {

      if (tempNode->data == data) {
        return i;
      }

      tempNode = tempNode->next;
    }
  } else {
    return buscaBinaria(lista, data, 0, getSize(lista) - 1);
  }

  return -1;
}

void ordenar(Lista *lista) {
  Node *nodeAtual = lista->head;
  int dado;
  while (nodeAtual != NULL) {
    Node *proximoNode = nodeAtual->next;
    while (proximoNode != NULL) {
      if (nodeAtual->data < proximoNode->data) {
        dado = nodeAtual->data;
        nodeAtual->data = proximoNode->data;
        proximoNode->data = dado;
      }
      proximoNode = proximoNode->next;
    }
    nodeAtual = nodeAtual->next;
  }
  lista->ordenado = 1;
}

// Função para realizar busca binária recursiva
int buscaBinaria(Lista *lista, int data, int i, int j) {
  if (i > j) {
    return -1;
  }

  int meio = (i + j) / 2;
  Node *tempNode = lista->head;
  for (int k = 0; k < meio; k++) {
    tempNode = tempNode->next;
  }

  if (tempNode == NULL) {
    return -1;
  }

  if (tempNode->data == data) {
    return i + (i + j) / 2;
  } else if (data < tempNode->data) {
    int iParameter = ((i + j) / 2 - 1);
    return buscaBinaria(lista, data, iParameter, j);
  } else {
    int iParameter = ((i + j) / 2 + 1);
    return buscaBinaria(lista, data, iParameter, j);
  }
}
