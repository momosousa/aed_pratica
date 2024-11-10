#include <stdio.h>
#include <stdlib.h>

#include "pilhadupla.h"

Pilha* criarPilha(int tamanho){

    Pilha* pilha=(Pilha*)malloc(sizeof(Pilha));
    if (pilha==NULL){
        printf("Erro ao alocar memória para a pilha\n");
        return;  // Termina o programa se a alocação falhar
    }
    pilha->valores=(int*)malloc(sizeof(int)*tamanho);  // Aloca memória para a estrutura pilha->valores

    pilha->topoA=-1;
    pilha->topoB=-1;
    for(int i=0;i<tamanho;i++){
        pilha->valores[i]=0;
    }
    pilha->tamanho=tamanho;

    return pilha;
}

Pilha* pushA(Pilha* pilha,int valor){

    if(pilha->topoA+1==pilha->topoB){
        printf("Todas as posicoes do vetor estao ocupadas!");
        return pilha;
    }
    pilha->topoA++;
    pilha->valores[pilha->topoA]=valor;

    return pilha;
}

Pilha* pushB(Pilha* pilha,int valor){

    if(pilha->topoA==pilha->topoB-1){
        printf("Todas as posicoes do vetor estao ocupadas!");
        return pilha;
    }
    if(pilha->topoB==-1){
        pilha->topoB=pilha->tamanho;
    }

    pilha->topoB--;
    pilha->valores[pilha->topoB]=valor;

    return pilha;
}

Pilha* popA(Pilha* pilha){
    //pop retorna o valor para o usuário, então vamos simplesmente alterar o valor do topo após printar o valor para o usuário
    if(pilha->topoA==-1){
        printf("\nNao existem mais valores na pilha A!");
        return pilha;
    }
    printf("%d ",pilha->valores[pilha->topoA]);
    pilha->topoA--;

    return pilha;
}

Pilha* popB(Pilha* pilha){

    if(pilha->topoB==pilha->tamanho){
        pilha->topoB=-1;
        printf("\nNao existem mais valores na pilha B!");
        return pilha;
    }

    //pop retorna o valor para o usuário, então vamos simplesmente alterar o valor do topo após printar o valor para o usuário
    printf("%d ",pilha->valores[pilha->topoB]);
    pilha->topoB++;

    return pilha;
}

Pilha* clearA(Pilha* pilha){
    //vamos chamar a função pop dentro de um laço de repetição
    do{
        popA(pilha);
    }while(pilha->topoA>=0);

    return pilha;
}

Pilha* clearB(Pilha* pilha){
    //vamos chamar a função pop dentro de um laço de repetição
    while(pilha->topoB<pilha->tamanho){
        popB(pilha);
    }

    return pilha;
}

void imprimirA(Pilha* pilha){

    printf("[|");
    for(int i=pilha->topoA;i>=0;i--){
        printf("%d|",pilha->valores[i]);
    }
    printf("]\n");

    return pilha;
}
void imprimirB(Pilha* pilha){

    printf("[|");
    for(int i=pilha->topoB;i<pilha->tamanho;i++){
        printf("%d|",pilha->valores[i]);
    }
    printf("]\n");

    return pilha;
}
