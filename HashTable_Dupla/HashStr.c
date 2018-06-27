#include <stdio.h>
#include <stdlib.h>
#include "HashStr.h"
#include <string.h>


HASHStr* cria_hashT(int k){
    HASHStr* no = (HASHStr*)malloc(sizeof(HASHStr));
    no->chaves= (NOME*)malloc(k * sizeof(NOME));
    int i;
    for (i = 0 ; i < k; i++)
        strcpy(no->chaves[i].nome, "-1");
    no->tam = k;

    return no;
}

HASHStr* insereHash(HASHStr* h, char* nome){
    int i = 1;
    int pos = (int)nome[0] % h->tam;
    while ( pos <= h->tam && strcmp(h->chaves[pos].nome, "-1") != 0 && strcmp(h->chaves[pos].nome, "-2")!= 0  ) {
        pos = ( pos + i * ( 1+ (((int)nome[0]) % ((h->tam)-2))) )% h->tam;
        i++;
    }
    if(strcmp(h->chaves[pos].nome, "-1") == 0 || strcmp(h->chaves[pos].nome, "-2") == 0)
        strcpy(h->chaves[pos].nome, nome );

    return h;
}

HASHStr* removeHash(HASHStr* h, char* nome){
    int i = 1;
    int pos = (int)nome[0] % h->tam;
    while (pos <= h->tam && strcmp(h->chaves[pos].nome, nome)!= 0) {
        pos = ( pos + i * ( 1+ (((int)nome[0]) % ((h->tam)-2))) )% h->tam;
        i++;
    }
    if (strcmp(h->chaves[pos].nome, nome)==0)
        strcpy(h->chaves[pos].nome, "-2" );

    return h;
}

void imprimeHash(HASHStr* h) {
    int i;
    for (i = 0; i < h->tam; i++) {
        if (strcmp(h->chaves[i].nome, "-1")==0 || strcmp(h->chaves[i].nome, "-2") == 0) {
                printf("vazia\n",i);
        } else{
            printf("%d - nome : %s \n", i, h->chaves[i].nome);
        }
    }
}

void liberaHash(HASHStr* h){
        free(h->chaves);
}
