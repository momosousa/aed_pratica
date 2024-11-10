#include "matrizEsparsa.h"

#include <stdio.h>
#include <stdlib.h>

// Função para criar um novo nó
Node *criarNode(int linha, int coluna, int valor) {
  Node *novoNode = (Node *)malloc(sizeof(Node));
  // if (novoNode == NULL) {
  //   printf("Erro: Alocação de memória!\n");
  //   exit(1);
  // }
  novoNode->valor = valor;
  novoNode->linha = linha;
  novoNode->coluna = coluna;
  novoNode->proximo = NULL;
  novoNode->abaixo = NULL;
  return novoNode;
}

// Função para criar a matriz esparsa
MatrizEsparsa *criarMatriz(int numLinhas, int numColunas) {
  MatrizEsparsa *matriz = (MatrizEsparsa *)malloc(sizeof(MatrizEsparsa));
  // if (matriz == NULL) {
  //   printf("Erro: Alocação de memória!\n");
  //   exit(1);
  // }
  matriz->numLinhas = numLinhas;
  matriz->numColunas = numColunas;
  matriz->linhas = (Node **)malloc(sizeof(Node *) * numLinhas);

  for (int i = 0; i < numLinhas; i++) {
    matriz->linhas[i] = NULL;
  }

  return matriz;
}

// Função para inserir ou atualizar um valor na posição especificada
void inserir(MatrizEsparsa *matriz, int linha, int coluna, int valor) {
  if (linha >= matriz->numLinhas || coluna >= matriz->numColunas || linha < 0 ||
      coluna < 0) {
    printf("Índice fora dos limites!\n");
    return;
  }

  Node *novoNode = criarNode(linha, coluna, valor);

  // Se a posição já contém um valor, removemos o nó antigo
  Node *anterior = NULL;
  Node *atual = matriz->linhas[linha];

  while (atual != NULL && atual->coluna < coluna) {
    anterior = atual;
    atual = atual->proximo;
  }

  if (atual != NULL && atual->coluna == coluna) {
    // Atualiza o valor
    atual->valor = valor;
    free(novoNode);
    return;
  }

  // Insere o novo nó na lista da linha
  if (anterior == NULL) {
    matriz->linhas[linha] = novoNode;
  } else {
    anterior->proximo = novoNode;
  }

  // Inserção na coluna
  Node *atualCol = matriz->linhas[coluna];
  anterior = NULL;

  while (atualCol != NULL && atualCol->linha < linha) {
    anterior = atualCol;
    atualCol = atualCol->abaixo;
  }

  if (anterior == NULL) {
    // Insere no início
    matriz->linhas[coluna] = novoNode;
  } else {
    anterior->abaixo = novoNode;
  }
}

// Função para remover um valor na posição especificada
void remover(MatrizEsparsa *matriz, int linha, int coluna) {

  // Elemento não existe
  if (linha >= matriz->numLinhas || coluna >= matriz->numColunas || linha < 0 ||
      coluna < 0) {
    return; // Finaliza função
  }

  Node *anterior = NULL;
  Node *atual = matriz->linhas[linha];

  while (atual != NULL && atual->coluna < coluna) {
    anterior = atual;
    atual = atual->proximo;
  }

  // Elemento já é zero
  if (atual == NULL || atual->coluna != coluna) {
    return; // Finaliza função
  }

  // Remover o nó da lista da linha
  if (anterior == NULL) {
    matriz->linhas[linha] = atual->proximo;
  } else {
    anterior->proximo = atual->proximo;
  }

  // Remover o nó da lista da coluna
  anterior = NULL;
  Node *atualCol = matriz->linhas[coluna];
  while (atualCol != NULL && atualCol->linha < linha) {
    anterior = atualCol;
    atualCol = atualCol->abaixo;
  }

  if (anterior == NULL) {
    matriz->linhas[coluna] = atual->abaixo;
  } else {
    anterior->abaixo = atual->abaixo;
  }

  free(atual);
}

// Função para buscar um valor na posição especificada
int buscar(MatrizEsparsa *matriz, int linha, int coluna) {
  Node *atual = matriz->linhas[linha];
  while (atual != NULL) {
    if (atual->coluna == coluna) {
      return atual->valor;
    }
    atual = atual->proximo;
  }
  return 0; // 0 se o valor não for encontrado
}

// Função para imprimir a matriz esparsa
void imprimir(MatrizEsparsa *matriz) {
  for (int i = 0; i < matriz->numLinhas; i++) {
    Node *atual = matriz->linhas[i];
    for (int j = 0; j < matriz->numColunas; j++) {
      if (atual != NULL && atual->coluna == j) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}

// Função para calcular o nível de esparsidade da matriz
float calculaEsparsidade(MatrizEsparsa *matriz) {
  int totalElementos = matriz->numLinhas * matriz->numColunas;
  int elementosNaoZero = 0;

  for (int i = 0; i < matriz->numLinhas; i++) {
    Node *atual = matriz->linhas[i];
    while (atual != NULL) {
      elementosNaoZero++;
      atual = atual->proximo;
    }
  }

  float esparsidade =
      (float)(totalElementos - elementosNaoZero) / totalElementos;
  return esparsidade;
}

// Função para somar todos os valores da matriz esparsa
int somaInterna(MatrizEsparsa *matriz) {
  int soma = 0;
  for (int i = 0; i < matriz->numLinhas; i++) {
    Node *atual = matriz->linhas[i];
    while (atual != NULL) {
      soma += atual->valor;
      atual = atual->proximo;
    }
  }
  return soma;
}

// Função para somar duas matrizes esparsas
MatrizEsparsa *somar(MatrizEsparsa *matriz1, MatrizEsparsa *matriz2) {
  if (matriz1->numLinhas != matriz2->numLinhas ||
      matriz1->numColunas != matriz2->numColunas) {
    printf("As matrizes devem ter o mesmo tamanho para soma!\n");
    return NULL;
  }

  // Cria uma nova matriz para armazenar o resultado
  MatrizEsparsa *resultado =
      criarMatriz(matriz1->numLinhas, matriz1->numColunas);

  // Passa por todas as linhas das duas matrizes
  for (int i = 0; i < matriz1->numLinhas; i++) {
    Node *n1 = matriz1->linhas[i]; // Lista da linha i de matriz1
    Node *n2 = matriz2->linhas[i]; // Lista da linha i de matriz2

    // Enquanto houver elementos em qualquer uma das duas listas
    while (n1 != NULL || n2 != NULL) {
      if (n1 != NULL && (n2 == NULL || n1->coluna < n2->coluna)) {
        // Se só existir o elemento de matriz1 (ou se for da coluna menor)
        inserir(resultado, i, n1->coluna,
                n1->valor); // Insere na matriz de resultado
        n1 = n1->proximo;   // Avança para o próximo elemento em matriz1
      } else if (n2 != NULL && (n1 == NULL || n2->coluna < n1->coluna)) {
        // Se só existir o elemento de matriz2 (ou se for da coluna menor)
        inserir(resultado, i, n2->coluna,
                n2->valor); // Insere na matriz resultado
        n2 = n2->proximo;   // Avança para o próximo elemento em matriz2
      } else if (n1 != NULL && n2 != NULL && n1->coluna == n2->coluna) {
        // Se ambos os elementos de matriz1 e matriz2 forem na mesma posição
        inserir(resultado, i, n1->coluna,
                n1->valor + n2->valor); // Soma os valores
        n1 = n1->proximo; // Avança para o próximo elemento em matriz1
        n2 = n2->proximo; // Avança para o próximo elemento em matriz2
      }
    }
  }

  return resultado;
}
