#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main()
{

    Tree* tree = createTree();

    tree->root = insert(tree->root, 17);

    tree->root = insert(tree->root, 6);

    tree->root = insert(tree->root, 35);

    tree->root = insert(tree->root, 4);

    tree->root = insert(tree->root, 14);

    tree->root = insert(tree->root, 23);

    tree->root = insert(tree->root, 48);

    printf("Arvore em ordem: ");
    strInorder(tree->root);
    printf("\n");

    int alvo = 6;
    int quantidadeSubNos = contarSubnosValor(tree->root, alvo);
    printf("No alvo: %d\n", alvo);
    printf("Quantidade de subnos: %d\n", quantidadeSubNos);

return 0;
}
