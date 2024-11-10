#include <stdio.h>
#include "fila_estaticaCircular.h"
#include "pilhaDinamica.h"

// Funcao para verificar se a fila esta balanceada ou nao (com base nos sinais de abertura e fechamento).
// Retorna 1 se a sequência estiver balanceada ou 0 se a sequência não estiver balanceada.
int verificaBalanceamento(Fila* fila) {

    // Cria uma pilha
    Pilha* pilha = criarPilha();
    // Verifica se deu erro para criar a pilha
    if (pilha == NULL) {
        printf("Erro ao criar a pilha!");
        exit(0);
    }

    // Fila auxiliar para conseguir preservar a fila original
    Fila* filaAux = criarFila(fila->capacity);
    // Verifica se deu erro para criar fila auxiliar
    if (filaAux == NULL) {
        free(pilha);
        exit(0);
    }

    // crio variaveis para usar como referencia (como flags)
    int balanceada = 1;  // Assumo que está balanceada até provar o contrario
    int sequenciaValida = 1; // Assumo que está válida até provar o contrario

    // Processa cada elemento da fila
    while (!isEmpty(fila)) {
        char elemento = dequeue(fila);
        enqueue(filaAux, elemento);  // Guarda o elemento na fila auxiliar (pra não perder a ordem original)

        // Verifico se os simbolos da fila são apenas sinais de abertura ou fechamento, se não for, retorna a flag como "0".
        if (elemento != '(' && elemento != ')' &&
            elemento != '[' && elemento != ']' &&
            elemento != '{' && elemento != '}') {
            sequenciaValida = 0;
            break;
        }

        //se for simbolo de abertura, coloco na pilha
        if (elemento == '(' || elemento == '[' || elemento == '{') {
            push(pilha, elemento);
        }

        // Se for símbolo de fechamento, verifica se corresponde ao último símbolo de abertura
        else if (elemento == ')' || elemento == ']' || elemento == '}') {

            // Se a pilha estiver vazia e ainda tiver um sinal de fechamento, retorna 0 (desbalanceada)
            if (isEmptyPilha(pilha)) {
                balanceada = 0;
                break;
            }

            char topo = pop(pilha);

            // Verifica se o par de símbolos corresponde, se forem diferente, retorna desbalanceada.
            if ((elemento == ')' && topo != '(') ||
                (elemento == ']' && topo != '[') ||
                (elemento == '}' && topo != '{')) {
                balanceada = 0;
                break;
            }
        }
    }

    // Se sobrou algum símbolo de abertura na pilha, a sequência não está balanceada
    if (!isEmptyPilha(pilha)) {
        balanceada = 0;
    }

    // Restaura a fila original copiando os elementos da fila auxiliar
    while (!isEmpty(filaAux)) {
        enqueue(fila, dequeue(filaAux));
    }

    //Libera a memória
    clearPilha(pilha);
    free(pilha);
    clear(filaAux);
    free(filaAux);

    //Usa a flag de sequencia valida para poder verificar se foi valido ou nao.
    if (!sequenciaValida) {
    printf("\nErro: Caractere invalido na fila!\n");
    return 0;  // Retorna 0 para indicar que não está balanceada
    }

    return balanceada;
}

int main() {
    // Criando a fila e definindo diretamente o seu tamanho (alterar por aqui)
    Fila* fila = criarFila(6);
    if (fila == NULL) {
        printf("Erro ao criar a fila.\n");
        return 1;
    }

    // Adicionando elementos na fila (adicionar por aqui)
    enqueue(fila, '(');
    enqueue(fila, '(');
    enqueue(fila, ')');
    enqueue(fila, ')');

    // Imprime a sequencia na tela
    printf("Sequencia:");
    imprimir(fila);

    // Imprime se esta balanceada ou não
    printf("\nStatus: %s.\n", verificaBalanceamento(fila) ? "Balanceada" : "Nao balanceada");

    clear(fila);
    free(fila);
    return 0;
}
