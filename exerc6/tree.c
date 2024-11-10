#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

Node* createNode(int data){
    Node* node = (Node*) malloc( sizeof(Node) );

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Tree* createTree(){
    Tree* tree = (Tree*) malloc( sizeof(Tree) );

    tree->root = NULL;
    return tree;
};

Node* insert( Node* node, int data ){

    if (node == NULL){
        Node* newNode = createNode(data);
        return newNode;
    }

    if (data < node->data){
        node->left = insert(node->left, data);
    }
    else{
        node->right = insert(node->right, data);
    }
    return node;
}

int search( Node* node, int data ){

    if (node == NULL){
        return 0;
    }

    if (data == node->data){
        return 1;
    }

    int achou;
    // verifica se vai para o lado esquerdo
    if (data < node->data){
        achou = search(node->left, data);
    }
    // vai para o lado direito
    else{
        achou = search(node->right, data);
    }

    return achou;

}

Node* getMaxNode( Node* node ){

    if (node == NULL){
        return NULL;
    }

    if (node->right == NULL){
        return node;
    }

    return getMaxNode( node->right );

}

Node* getMinNode( Node* node ){

    if (node == NULL){
        return NULL;
    }

    if (node->left == NULL){
        return node;
    }

    return getMinNode( node->left );

}

Node* deleteNode( Node* node, int data,
                    char filhoSubstituto){

    if (node == NULL){
        return node;
    }

    if (data < node->data){
        node->left = deleteNode( node->left, data,
                                      filhoSubstituto);
    }
    else if( data > node->data ){
         node->right = deleteNode( node->right, data,
                                      filhoSubstituto);
    }
    else{
        // encontrou o noh que sera excluido
        if(node->left == NULL){
            Node* tempNode = node->right;
            free(node);
            return tempNode;
        }
        else if( node->right == NULL ){
            Node* tempNode = node->left;
            free(node);
            return tempNode;
        }
        else{
            // o noh possui dois filhos
            Node* tempNode;
            if( filhoSubstituto == 'D' ){
                // o menor de todos do lado direito
                tempNode = getMinNode(node->right);
                node->data = tempNode->data;
                node->right = deleteNode(node->right,
                                        tempNode->data,
                                        filhoSubstituto);
            }
            else{
                // o maior de todos do lado esquerdo
                tempNode = getMaxNode(node->left);
                node->data = tempNode->data;
                node->left = deleteNode(node->left,
                                        tempNode->data,
                                        filhoSubstituto);
            }
        }
    } // fecha o else

    return node;
}

void strPreorder(Node *node){
    if( node != NULL ){

        printf("%d ", node->data );
        strPreorder(node->left);
        strPreorder(node->right);
    }
}


// Função para percorrer a árvore em ordem
void strInorder(Node *node) {
    if (node != NULL) {

        strInorder(node->left);
        printf("%d ", node->data);
        strInorder(node->right);
    }
}

// Função para percorrer a árvore em pós-ordem
void strPostorder(Node *node) {
    if (node != NULL) {

        strPostorder(node->left);
        strPostorder(node->right);
        printf("%d ", node->data);
    }
}

// Função auxiliar que conta recursivamente o número total de nós
int contarSubNos(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + contarSubNos(node->left) + contarSubNos(node->right); // ele mesmo + direita + esquerda
}

/*
Função que busca um nó com um valor específico na arvore e retorna o número total de nós na subárvore que tem esse valor como raiz.

Busca o nó com o valor desejado e chama contarSubNos() para contar todos os nós abaixo dele.
Se não encontrar o valor, retorna 0
*/

 int contarSubnosValor(Node* node, int valor) {
    if (node == NULL) {
        return 0;
    }
    if (node->data == valor) {
        return contarSubNos(node); // Chama a função auxiliar no nó encontrado
    }
    // Se o valor é menor, busca no lado esquerdo, senão, no direito
    if (valor < node->data) {
        return contarSubnosValor(node->left, valor);
    } else {
        return contarSubnosValor(node->right, valor);
    }
}



