#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Fila {
    int *fila;
    int tamanho;
} Fila;

Fila *fila_criar() {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    fila->fila = (int *) malloc(sizeof(int));
    fila->tamanho = 0;
    return fila;
}

int fila_esta_vazia(Fila *fila) {
    return fila->tamanho == 0;
}

int fila_tamanho(Fila *fila) {
    return fila->tamanho;
}

void fila_enfileirar(Fila *fila, int elemento) {
    fila->fila = (int *) realloc(fila->fila, (fila->tamanho + 1) * sizeof(int));
    fila->fila[fila->tamanho] = elemento;
    fila->tamanho++;
}

int fila_desenfileirar(Fila *fila) {
    if (fila_esta_vazia(fila)) {
        return -1;
    }
    int elemento = fila->fila[0];
    for (int i = 0; i < fila->tamanho - 1; i++) {
        fila->fila[i] = fila->fila[i + 1];
    }
    fila->tamanho--;
    fila->fila = (int *) realloc(fila->fila, fila->tamanho * sizeof(int));
    return elemento;
}

int fila_frente(Fila *fila) {
    if (fila_esta_vazia(fila)) {
        return -1;
    }
    return fila->fila[0];
}

void fila_destruir(Fila *fila) {
    free(fila->fila);
    free(fila);
}

int main() {
    Fila *fila = fila_criar();
    fila_enfileirar(fila, 1);
    fila_enfileirar(fila, 2);
    fila_enfileirar(fila, 3);
    printf("%d\n", fila_tamanho(fila));
    printf("%d\n", fila_frente(fila));
    printf("%d\n", fila_desenfileirar(fila));
    printf("%d\n", fila_esta_vazia(fila));
    fila_destruir(fila);
    return 0;
}
 

