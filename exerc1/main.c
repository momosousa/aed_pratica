#include <stdio.h>
#include "fila_estaticaCircular.h"
#include "pilhaDinamica.h"
#include "pilhaDinamica.c"

int verificaBalanceamento(Fila* fila) {
    Pilha* pilha = criarPilha();
    while (!isEmpty(fila)) {
        char elemento = dequeue(fila);
        if (elemento == '(' || elemento == '[' || elemento == '{') {
            push(pilha, elemento);
        } else if (elemento == ')' || elemento == ']' || elemento == '}') {
            if (isEmpty(pilha) ||
                (elemento == ')' && pop(pilha) != '(') ||
                (elemento == ']' && pop(pilha) != '[') ||
                (elemento == '}' && pop(pilha) != '{')) {
                clear(pilha);
                free(pilha);
                return 0;
            }
        }
    }
    int balanceada = isEmpty(pilha) ? 1 : 0;
    clear(pilha);
    free(pilha);
    return balanceada;
}

int main() {
    int tamanho;
    while (1) {
        printf("Tamanho da fila: ");
        if (scanf("%d", &tamanho) == 1 && tamanho > 0) {
            if (tamanho % 2 != 0) {
                printf("Sequencia nao balanceada, numero de elementos impar.\n");
                return 0;
            }
            break;
        } else {
            printf("Erro. Por favor, insira um numero inteiro positivo.\n");
            while (getchar() != '\n');
        }
    }

    Fila* fila = criarFila(tamanho);
    if (fila == NULL) {
        printf("Erro ao criar a fila.\n");
        return 1;
    }

    char sequencia[tamanho + 1];
    printf("Digite a sequencia de sinais: ");
    scanf("%s", sequencia);

    int contador = 0;
    for (int i = 0; sequencia[i] != '\0'; i++) {
        char elemento = sequencia[i];
        if (elemento == '(' || elemento == ')' || elemento == '{' || elemento == '}' || elemento == '[' || elemento == ']') {
            if (contador < tamanho) {
                enqueue(fila, elemento);
                contador++;
            } else {
                printf("Overflow: a sequencia tem mais elementos do que o permitido.\n");
                clear(fila);
                free(fila);
                return 0;
            }
        } else {
            printf("Erro -> '%c'! Digite apenas '()', '{}', '[]'.\n", elemento);
            clear(fila);
            free(fila);
            return 1;
        }
    }

    printf("Sequencia %s.\n", verificaBalanceamento(fila) ? "balanceada" : "nao balanceada");

    clear(fila);
    free(fila);

    return 0;
}
