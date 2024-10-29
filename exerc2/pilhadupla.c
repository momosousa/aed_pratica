#include <stdio.h>
#include <stdlib.h>

#include "pilhadupla.h"

Pilha* criarPilha(){

    Pilha* pilha=(Pilha*)malloc(sizeof(Pilha));  // Aloca mem�ria para a estrutura Pilha
    if (pilha==NULL){
        printf("Erro ao alocar mem�ria para a pilha\n");
        return;  // Termina o programa se a aloca��o falhar
    }
    pilha->topoA=-1;
    pilha->topoB=-1;
    for(int i=0;i<TAMANHO;i++){
        pilha->valores[i]=0;
    }

    return pilha;
}

Pilha* pushA(Pilha* pilha,int valor){

    if(pilha->topoA+1==pilha->topoB){
        printf("Todas as posicoes do vetor estao ocupadas!");
        return;
    }
    pilha->topoA++;
    pilha->valores[pilha->topoA]=valor;

    return pilha;
}

Pilha* pushB(Pilha* pilha,int valor){

    if(pilha->topoA==pilha->topoB-1){
        printf("Todas as posicoes do vetor estao ocupadas!");
        return;
    }
    if(pilha->topoB==-1){
        pilha->topoB=TAMANHO;
    }

    pilha->topoB--;
    pilha->valores[pilha->topoB]=valor;

    return pilha;
}

Pilha* popA(Pilha* pilha){
    //pop retorna o valor para o usu�rio, ent�o vamos simplesmente alterar o valor do topo ap�s printar o valor para o usu�rio
    if(pilha->topoA==-1){
        printf("\nNao existem mais valores na pilha A!");
        return;
    }
    printf("%d ",pilha->valores[pilha->topoA]);
    pilha->topoA--;

    return pilha;
}

Pilha* popB(Pilha* pilha){

    if(pilha->topoB==TAMANHO){
        pilha->topoB=-1;
        printf("\nNao existem mais valores na pilha B!");
        return;
    }

    //pop retorna o valor para o usu�rio, ent�o vamos simplesmente alterar o valor do topo ap�s printar o valor para o usu�rio
    printf("%d ",pilha->valores[pilha->topoB]);
    pilha->topoB++;

    return pilha;
}

Pilha* clearA(Pilha* pilha){
    //vamos chamar a fun��o pop dentro de um la�o de repeti��o
    do{
        popA(pilha);
    }while(pilha->topoA>=0);

    return pilha;
}

Pilha* clearB(Pilha* pilha){
    //vamos chamar a fun��o pop dentro de um la�o de repeti��o
    while(pilha->topoB<TAMANHO){
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
    for(int i=pilha->topoB;i<TAMANHO;i++){
        printf("%d|",pilha->valores[i]);
    }
    printf("]\n");

    return pilha;
}
