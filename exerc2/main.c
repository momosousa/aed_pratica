#include <stdio.h>
#include <stdlib.h>

#include "pilhadupla.h"

int main()
{
    Pilha* pilha=criarPilha();

    printf("Inserir 18 na pilha A: ");
    pushA(pilha,18);
    printf("\n\nImprimindo a pilha A: ");
    imprimirA(pilha);

    printf("\n\nInserir 30 na pilha A: ");
    pushA(pilha,30);
    printf("\n\nImprimindo a pilha A: ");
    imprimirA(pilha);

    printf("\n\nInserir 54 na pilha A: ");
    pushA(pilha,54);
    printf("\n\nImprimindo a pilha A: ");
    imprimirA(pilha);

    printf("\n\nInserir 81 na pilha A: ");
    pushA(pilha,81);
    printf("\n\nImprimindo a pilha A: ");
    imprimirA(pilha);

    printf("\n\nInserir 7 na pilha A: ");
    pushA(pilha,7);
    printf("\n\nImprimindo a pilha A: ");
    imprimirA(pilha);

    printf("\n\nInserir 5 na pilha A: ");
    pushA(pilha,5);
    printf("\n\nImprimindo a pilha A: ");
    imprimirA(pilha);

    printf("\n\nInserir 9 na pilha A: ");
    pushA(pilha,9);
    printf("\n\nImprimindo a pilha A: ");
    imprimirA(pilha);

    printf("\n\ninserir 9 na pilha B: ");
    pushB(pilha,9);
    printf("\n\nImprimindo a pilha B: ");
    imprimirB(pilha);

    printf("\n\ninserir 8 na pilha B: ");
    pushB(pilha,8);
    printf("\n\nImprimindo a pilha B: ");
    imprimirB(pilha);

    printf("\n\ninserir 23 na pilha B: ");
    pushB(pilha,23);
    printf("\n\nImprimindo a pilha B: ");
    imprimirB(pilha);

    printf("\n\ninserir 39 na pilha B: ");
    pushB(pilha,39);
    printf("\n\nImprimindo a pilha B: ");
    imprimirB(pilha);

    printf("\n\nLimpando a pilha A: ");
    clearA(pilha);

    printf("\n\nImprimindo a pilha A apos ela ter sido limpa: ");
    imprimirA(pilha);

    printf("\n\nLimpando a pilha B: ");
    clearB(pilha);

    printf("\n\nImprimindo a pilha B apos ela ter sido limpa: ");
    imprimirB(pilha);

    return 0;
}
