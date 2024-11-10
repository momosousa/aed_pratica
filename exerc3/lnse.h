#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H

#define MAX 10
#define VAZIO -1 // Indica posição vazia

typedef struct {
    int valor;
    int prox;
} Nodo;

typedef struct {
    Nodo elementos[MAX];
    int head;        // Índice do primeiro elemento na lista
    int tail;        // Índice do último elemento na lista
    int tamanho;     // Número de elementos na lista
    int filaVazia[MAX]; // Fila estática para controle de posições vazias
    int inicioFila;  // Índice do início da fila
    int fimFila;     // Índice do fim da fila
} ListaEstatica;

// Funções da lista estática
void inicializar(ListaEstatica *lista);
void inserir(ListaEstatica *lista, int x, int i);
int remover(ListaEstatica *lista, int i);
int buscar(ListaEstatica *lista, int x);
int size(ListaEstatica *lista);
void clear(ListaEstatica *lista);
void imprimir(ListaEstatica *lista);

#endif // LISTA_ESTATICA_H

