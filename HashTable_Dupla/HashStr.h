#ifndef HASHDUPLA_HASHD_H
#define HASHDUPLA_HASHD_H

typedef struct name{
    char nome[20];
}NOME;

typedef struct hashstr{
    NOME *chaves;
    int tam;
}HASHStr;

HASHStr* cria_hashT(int k);

void imprimeHash(HASHStr* h);

HASHStr* insereHash(HASHStr* h, char* nome);
HASHStr* removeHash(HASHStr* h, char* nome);


void liberaHash(HASHStr* h);

#endif
