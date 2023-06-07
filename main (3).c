#include <stdio.h>
#include <stdlib.h>

int busca_sequencial(int lista[], int elemento){
    int i;
    for(i=0; i<sizeof(lista); i++){
        if(lista[i] == elemento){
            return i;
        }
    }
    return -1;
}

int main(){
    int lista[] = {4, 2, 9, 1, 7, 5};
    int elemento = 9;
    int indice = busca_sequencial(lista, elemento);
    if(indice != -1){
        printf("O elemento %d foi encontrado no indice %d.", elemento, indice);
    }else{
        printf("O elemento %d nao foi encontrado na lista.", elemento);
    }
    return 0;
}
 
#