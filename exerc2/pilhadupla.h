#ifndef PILHADUPLA_H_INCLUDED
#define PILHADUPLA_H_INCLUDED

#define TAMANHO 10

typedef struct Pilha{

    //definindo uma struct do tipo Pilha para passar como par�metro para as fun��es e facilitar o uso dos valores e topos podendo alter�-los de uma s� vez e retornando somente uma pilha do tipo Pilha
    int topoA;
    int topoB;
    int valores[TAMANHO];

}Pilha;

Pilha* criarPilha();

// Fun��es de manipula��o da pilha dupla
Pilha* pushA(Pilha* pilha, int valor);
Pilha* pushB(Pilha* pilha, int valor);

Pilha* popA(Pilha* pilha);
Pilha* popB(Pilha* pilha);

Pilha* clearA(Pilha* pilha);
Pilha* clearB(Pilha* pilha);

void imprimirA(Pilha* pilha);
void imprimirB(Pilha* pilha);

#endif // PILHADUPLA_H_INCLUDED
