#ifndef PILHADUPLA_H_INCLUDED
#define PILHADUPLA_H_INCLUDED


typedef struct Pilha{

    //definindo uma struct do tipo Pilha para passar como parâmetro para as funções e facilitar o uso dos valores e topos podendo alterá-los de uma só vez e retornando somente uma pilha do tipo Pilha
    int topoA;
    int topoB;
    int tamanho;
    int* valores;

}Pilha;

Pilha* criarPilha(int tamanho);

// Funções de manipulação da pilha dupla
Pilha* pushA(Pilha* pilha, int valor);
Pilha* pushB(Pilha* pilha, int valor);

Pilha* popA(Pilha* pilha);
Pilha* popB(Pilha* pilha);

Pilha* clearA(Pilha* pilha);
Pilha* clearB(Pilha* pilha);

void imprimirA(Pilha* pilha);
void imprimirB(Pilha* pilha);

#endif // PILHADUPLA_H_INCLUDED
