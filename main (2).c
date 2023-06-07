#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha {
    int *pilha;
    int tamanho;
} Pilha;

Pilha *criar_pilha() {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    pilha->pilha = (int *) malloc(sizeof(int));
    pilha->tamanho = 0;
    return pilha;
}

int esta_vazia(Pilha *pilha) {
    return pilha->tamanho == 0;
}

int tamanho(Pilha *pilha) {
    return pilha->tamanho;
}

void empilhar(Pilha *pilha, int elemento) {
    pilha->pilha = (int *) realloc(pilha->pilha, sizeof(int) * (pilha->tamanho + 1));
    pilha->pilha[pilha->tamanho] = elemento;
    pilha->tamanho++;
}

int desempilhar(Pilha *pilha) {
    if (esta_vazia(pilha)) {
        return -1;
    }
    int elemento = pilha->pilha[pilha->tamanho - 1];
    pilha->pilha = (int *) realloc(pilha->pilha, sizeof(int) * (pilha->tamanho - 1));
    pilha->tamanho--;
    return elemento;
}

int topo(Pilha *pilha) {
    if (esta_vazia(pilha)) {
        return -1;
    }
    return pilha->pilha[pilha->tamanho - 1];
}

int main() {
    Pilha *pilha = criar_pilha();
    empilhar(pilha, 1);
    empilhar(pilha, 2);
    empilhar(pilha, 3);
    printf("%d\n", tamanho(pilha)); // Saída: 3
    printf("%d\n", topo(pilha)); // Saída: 3
    int elemento = desempilhar(pilha);
    printf("%d\n", elemento); // Saída: 3
    printf("%d\n", esta_vazia(pilha)); // Saída: 0
    return 0;
}
#