#ifndef HAS_H_INCLUDED
#define HAS_H_INCLUDED
#include "RBTree.h"

typedef struct hashtree{
    Tree** Table;
    int tam;
}HASHTree;

HASHTree* cria_hashT(int k);
void imprime_escolhendo(HASHTree* h, int op);
void imprime_pre(HASHTree* hashT);
void imprime_in(HASHTree* hashT);
void imprime_pos(HASHTree* hashT);
void insereHash(HASHTree* hashT, int k);
void removeHash(HASHTree* hashT, int k);
void liberaHash(HASHTree* h);


#endif
