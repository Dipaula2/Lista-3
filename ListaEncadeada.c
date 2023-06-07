#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *proximo;
}No;

typedef struct listaEncadeada{
    No *primeiro;
}ListaEncadeada;

void adicionar(ListaEncadeada *lista, int dado){
    No *novo_no = (No*)malloc(sizeof(No));
    novo_no->dado = dado;
    novo_no->proximo = NULL;

    if(lista->primeiro == NULL){
        lista->primeiro = novo_no;
    }else{
        No *atual = lista->primeiro;
        while(atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual->proximo = novo_no;
    }
}

void remover(ListaEncadeada *lista, int dado){
    if(lista->primeiro == NULL){
        return;
    }

    if(lista->primeiro->dado == dado){
        lista->primeiro = lista->primeiro->proximo;
        return;
    }

    No *atual = lista->primeiro;
    while(atual->proximo != NULL){
        if(atual->proximo->dado == dado){
            atual->proximo = atual->proximo->proximo;
            return;
        }
        atual = atual->proximo;
    }
}

void imprimir(ListaEncadeada *lista){
    if(lista->primeiro == NULL){
        printf("A lista está vazia.\n");
        return;
    }

    No *atual = lista->primeiro;
    while(atual != NULL){
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

int main(){
    ListaEncadeada *lista = (ListaEncadeada*)malloc(sizeof(ListaEncadeada));
    lista->primeiro = NULL;

    adicionar(lista, 1);
    adicionar(lista, 2);
    adicionar(lista, 3);
    adicionar(lista, 4);
    imprimir(lista);

    remover(lista, 3);
    imprimir(lista);

    return 0;
}




