#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int lista[], int elemento) {
    int inicio = 0;
    int fim = sizeof(lista) - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (lista[meio] == elemento) {
            return meio;
        } else if (lista[meio] < elemento) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int main() {
    int lista[] = {1, 2, 4, 5, 7, 9};
    int elemento = 5;

    int indice = busca_binaria(lista, elemento);
    if (indice != -1) {
        printf("O elemento %d foi encontrado no índice %d.", elemento, indice);
    } else {
        printf("O elemento %d não foi encontrado na lista.", elemento);
    }

    return 0;
}
 
#
