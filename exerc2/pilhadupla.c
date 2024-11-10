#include <stdio.h>
#include <stdlib.h>

#include "pilhadupla.h"

Pilha* criarPilha(){

    Pilha* pilha=(Pilha*)malloc(sizeof(Pilha));  // Aloca memoria para a estrutura Pilha
    if (pilha==NULL){
        printf("Erro ao alocar mem�ria para a pilha\n");
        return;  // Termina o programa se a alocacao falhar
    }
    pilha->topoA=-1;
    pilha->topoB=-1;
    
    //para efeito de prática estou definindo todos os valors do vetor como 0 para não ter lixo de memória (não fará diferença no resultado final)
    for(int i=0;i<TAMANHO;i++){
        pilha->valores[i]=0;
    }

    return pilha;
}

Pilha* pushA(Pilha* pilha,int valor){

    //verificando se quando formos dar um novo push, mudando portanto o topo da pilha, se o novo topo da pilha A (topoA+1) será igual ao topo da pilha B, se forem iguais, o vetor está completamente cheio
    if(pilha->topoA+1==pilha->topoB){
        printf("Todas as posicoes do vetor estao ocupadas!");
        return;
    }
    pilha->topoA++;
    pilha->valores[pilha->topoA]=valor;

    return pilha;
}

Pilha* pushB(Pilha* pilha,int valor){

    //verificando se o novo topo da pilha B ( caso o push for ocorrer ) estará ocupado, isto é, o topo da pilha A será igual ao topo da pilha B
    if(pilha->topoA==pilha->topoB-1){
        printf("Todas as posicoes do vetor estao ocupadas!");
        return;
    }

    //a pilha B está vazia
    if(pilha->topoB==-1){
        pilha->topoB=TAMANHO;
    }

    pilha->topoB--;
    pilha->valores[pilha->topoB]=valor;

    return pilha;
}

Pilha* popA(Pilha* pilha){
    //pop retorna o valor para o usuario, entao vamos simplesmente alterar o valor do topo apos printar o valor para o usuario
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
    //vamos chamar a funcao pop dentro de um laco de repeticao
    do{
        popA(pilha);
    }while(pilha->topoA>=0);

    return pilha;
}

Pilha* clearB(Pilha* pilha){
    //vamos chamar a funcao pop dentro de um laco de repeticao
    while(pilha->topoB<TAMANHO){
        popB(pilha);
    }

    return pilha;
}

void imprimirA(Pilha* pilha){

    //laco de repeticao para printar os valores da pilha A
    printf("[|");
    for(int i=pilha->topoA;i>=0;i--){
        printf("%d|",pilha->valores[i]);
    }
    printf("]\n");

    return pilha;
}
void imprimirB(Pilha* pilha){

    //laco de repeticao para printar os valores da pilha B
    printf("[|");
    for(int i=pilha->topoB;i<TAMANHO;i++){
        printf("%d|",pilha->valores[i]);
    }
    printf("]\n");

    return pilha;
}
