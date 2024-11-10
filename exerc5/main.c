#include <stdio.h>
#include <stdlib.h>

#include "matrizEsparsa.h"

int main() {
  // Exemplo de uso da matriz esparsa
  MatrizEsparsa *matriz1 = criarMatriz(3, 3);
  MatrizEsparsa *matriz2 = criarMatriz(3, 3);

  // Inserindo valores na matriz1
  printf("Inserindo valores na Matriz 1:\n");
  printf("inserir(matriz1, 0, 0, 5)\n");
  printf("inserir(matriz1, 1, 2, 8)\n");
  printf("inserir(matriz1, 2, 1, 3)\n");
  inserir(matriz1, 0, 0, 5);
  inserir(matriz1, 1, 2, 8);
  inserir(matriz1, 2, 1, 3);

  // Inserindo valores na matriz2
  printf("\nInserindo valores na Matriz 2:\n");
  printf("inserir(matriz2, 0, 1, 4)\n");
  printf("inserir(matriz2, 1, 0, 7)\n");
  printf("inserir(matriz2, 2, 2, 9)\n");
  inserir(matriz2, 0, 1, 4);
  inserir(matriz2, 1, 0, 7);
  inserir(matriz2, 2, 2, 9);

  // Imprimir as matrizes
  printf("\nMatriz 1:\n");
  imprimir(matriz1);
  printf("\nMatriz 2:\n");
  imprimir(matriz2);

  // Somando as matrizes
  MatrizEsparsa *matrizSoma = somar(matriz1, matriz2);
  printf("\nSoma da Matriz 1 e Matriz 2:\n");
  imprimir(matrizSoma);

  // Soma interna
  printf("\nSoma Interna da Matriz 1: %d\n", somaInterna(matriz2));
  printf("\nSoma Interna da Matriz 2: %d\n", somaInterna(matriz2));

  // Remover um elemento que existe
  printf("\nRemovendo L0 C0 da Matriz 1\n");
  remover(matriz1, 0, 0);

  // Imprimindo matriz 1 após remoção do L0 C0
  printf("\nMatriz 1 após remoção:\n");
  imprimir(matriz1);

  // Inserindo valor no elmento L1 C1
  printf("\nInserindo 10 no elemento L1 C1 da Matriz 1\n");
  inserir(matriz1, 1, 1, 10);

  // Imprimindo matriz 1 após inserção do L1 C1
  printf("\nMatriz 1 após inserção:\n");
  imprimir(matriz1);

  // Buscando o valor do elemento L1 C1
  printf("\nBusca - Valor do elemento L1 C1 na Matriz 1: %d\n", buscar(matriz1, 1, 1));
  printf("\nBusca - Valor do elemento L2 C1 na Matriz 1: %d\n", buscar(matriz1, 2, 1));
  printf("\nBusca - Valor de elemento L4 C4 (não existe) na Matriz 1: %d\n", buscar(matriz1, 4, 4));

  // Esparsidade
  printf("\nEsparsidade da Matriz 1: %.2f\n", calculaEsparsidade(matriz1));
  printf("\nEsparsidade da Matriz 2: %.2f\n", calculaEsparsidade(matriz2));
  
  // liberarMatriz(matriz1);
  // liberarMatriz(matriz2);
  

  return 0;
}
