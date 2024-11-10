#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

// A função que criei está desenvolvida no final do arquivo tree.c!!

int main()
{

    // cria a árvore
    Tree* tree = createTree();

    // insere os elementos na árvore
    tree->root = insert(tree->root, 17);

    tree->root = insert(tree->root, 6);

    tree->root = insert(tree->root, 35);

    tree->root = insert(tree->root, 4);

    tree->root = insert(tree->root, 14);

    tree->root = insert(tree->root, 23);

    tree->root = insert(tree->root, 48);

    //imprime a arvore em ordem
    printf("Arvore em ordem: ");
    strInorder(tree->root);
    printf("\n");

    // define quem vamos buscar
    int alvo = 6;

    //chama a função para contar os subnos, coloca a resposta em uma variavel
    int quantidadeSubNos = contarSubnosValor(tree->root, alvo);

    //imprime o alvo e a resposta
    printf("No alvo: %d\n", alvo);
    printf("Quantidade de subnos: %d\n", quantidadeSubNos);

return 0;
}
