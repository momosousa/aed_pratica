#ifndef MATRIZESPARSA_H_INCLUDED
#define MATRIZESPARSA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da matriz esparsa
typedef struct Node {
  int valor;
  int linha;
  int coluna;
  struct Node *proximo; // Ponteiro para o próximo nó na linha
  struct Node *abaixo;  // Ponteiro para o próximo nó na coluna
} Node;

// Estrutura da matriz esparsa
typedef struct MatrizEsparsa {
  Node **linhas; // Listas para cada linha
  int numLinhas;
  int numColunas;
} MatrizEsparsa;

Node *criarNode(int linha, int coluna, int valor);

MatrizEsparsa *criarMatriz(int numLinhas, int numColunas);

// Insere ou atualiza um valor não-nulo na posição especificada
void inserir(MatrizEsparsa *matriz, int linha, int coluna, int valor);

// Remove o elemento na posição especificada, se ele existir.
void remover(MatrizEsparsa *matriz, int linha, int coluna);

// Retorna o valor na  posição especificada (linha, coluna). Se o valor não
// existir (ou for zero), retorna zero.
int buscar(MatrizEsparsa *matriz, int linha, int coluna);

// Imprime a matriz completa, exibindo os valores em suas respectivas posições
void imprimir(MatrizEsparsa *matriz);

// Retorna o nível de esparsidade da matriz, que é a proporção de elementos zero
// em relação ao total de elementos.
float calculaEsparsidade(MatrizEsparsa *matriz);

// Retorna uma nova matriz esparsa que é o resultado da soma da matriz atual com
// outra matriz esparsa. As duas matrizes devem ter o mesmo tamanho.
MatrizEsparsa *somar(MatrizEsparsa *matriz1, MatrizEsparsa *matriz2);

// Soma todos os valores da matriz esparsa.
int somaInterna(MatrizEsparsa *matriz);

#endif // MATRIZESPARSA_H_INCLUDED
