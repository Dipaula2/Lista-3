#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TabelaHash {
    int tamanho;
    int num_elementos;
    struct Item **tabela;
};

struct Item {
    char *chave;
    char *valor;
    struct Item *proximo;
};

struct TabelaHash *criar_tabela_hash(int tamanho);
int funcao_hash(struct TabelaHash *tabela, char *chave);
void inserir(struct TabelaHash *tabela, char *chave, char *valor);
char *buscar(struct TabelaHash *tabela, char *chave);
void remover(struct TabelaHash *tabela, char *chave);
void imprimir(struct TabelaHash *tabela);
int tamanho(struct TabelaHash *tabela);

struct TabelaHash *criar_tabela_hash(int tamanho) {
    struct TabelaHash *tabela = malloc(sizeof(struct TabelaHash));
    tabela->tamanho = tamanho;
    tabela->num_elementos = 0;
    tabela->tabela = malloc(sizeof(struct Item *) * tamanho);
    for (int i = 0; i < tamanho; i++) {
        tabela->tabela[i] = NULL;
    }
    return tabela;
}

int funcao_hash(struct TabelaHash *tabela, char *chave) {
    int total = 0;
    for (int i = 0; i < strlen(chave); i++) {
        total += (int) chave[i];
    }
    return total % tabela->tamanho;
}

void inserir(struct TabelaHash *tabela, char *chave, char *valor) {
    int indice = funcao_hash(tabela, chave);
    struct Item *item = tabela->tabela[indice];
    while (item != NULL) {
        if (strcmp(item->chave, chave) == 0) {
            item->valor = valor;
            return;
        }
        item = item->proximo;
    }
    item = malloc(sizeof(struct Item));
    item->chave = chave;
    item->valor = valor;
    item->proximo = tabela->tabela[indice];
    tabela->tabela[indice] = item;
    tabela->num_elementos++;
}

char *buscar(struct TabelaHash *tabela, char *chave) {
    int indice = funcao_hash(tabela, chave);
    struct Item *item = tabela->tabela[indice];
    while (item != NULL) {
        if (strcmp(item->chave, chave) == 0) {
            return item->valor;
        }
        item = item->proximo;
    }
    return NULL;
}

void remover(struct TabelaHash *tabela, char *chave) {
    int indice = funcao_hash(tabela, chave);
    struct Item *item = tabela->tabela[indice];
    struct Item *anterior = NULL;
    while (item != NULL) {
        if (strcmp(item->chave, chave) == 0) {
            if (anterior == NULL) {
                tabela->tabela[indice] = item->proximo;
            } else {
                anterior->proximo = item->proximo;
            }
            free(item);
            tabela->num_elementos--;
            return;
        }
        anterior = item;
        item = item->proximo;
    }
}

void imprimir(struct TabelaHash *tabela) {
    for (int i = 0; i < tabela->tamanho; i++) {
        printf("Índice %d: ", i);
        struct Item *item = tabela->tabela[i];
        while (item != NULL) {
            printf("(%s, %s) ", item->chave, item->valor);
            item = item->proximo;
        }
        printf("\n");
    }
}

int tamanho(struct TabelaHash *tabela) {
    return tabela->num_elementos;
}

int main() {
    struct TabelaHash *tabela = criar_tabela_hash(10);
    inserir(tabela, "chave1", "valor1");
    inserir(tabela, "chave2", "valor2");
    inserir(tabela, "chave3", "valor3");
    imprimir(tabela);

    printf("%s\n", buscar(tabela, "chave2"));

    remover(tabela, "chave1");
    imprimir(tabela);

    return 0;
}
