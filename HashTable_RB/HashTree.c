#include <stdio.h>
#include <stdlib.h>
#include "HashTree.h"

HASHTree* cria_hashT(int k){
    HASHTree* no = (HASHTree*)malloc(sizeof(HASHTree));
    no->Table = (Tree**)malloc(k * sizeof(Tree));

    int i;
    for (i = 0 ; i<k; i++)
        no->Table[i] = criaTree();

    no->tam = k;

    return no;
}

void imprime_escolhendo(HASHTree* h, int op){
    if (op == 1)
        imprime_pre(h);
    else if (op == 2)
        imprime_in(h);
    else if (op == 3)
        imprime_pos(h);
}

void imprime_pre(HASHTree* h){
    int i;
    for (i =0; i< h->tam; i++){
        imprime_escolhendo_orde(h->Table[i],1);
        printf("\n");
    }
}

void imprime_in(HASHTree* h){
    int i;
    for (i =0; i< h->tam; i++){
        imprime_escolhendo_orde(h->Table[i],2);
        printf("\n");
    }

}

void imprime_pos(HASHTree* h){
    int i;
    for (i =0; i< h->tam; i++){
        imprime_escolhendo_orde(h->Table[i],3);
        printf("\n");
    }

}

void insereHash(HASHTree * h, int k){
     int pos = k % h->tam;
     h->Table[pos]->raiz = Rb_insert(h->Table[pos],cria_no(k));
}

void removeHash(HASHTree* h, int k){
    int pos = k % h->tam;
    h->Table[pos]->raiz = Rb_remove(h->Table[pos],cria_no(k));

}
void liberaHash(HASHTree* h){
    int i;
    for (i = 0; i < h->tam; i++){
        libera(h->Table[i]);
        free(h->Table[i]);
    }
}
