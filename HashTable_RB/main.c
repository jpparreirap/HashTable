#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "HashTree.h"

int main(){
    int tam;

    printf("Digite o Tamanho da Tabela Hash: \n");
    scanf("%d",&tam);

     HASHTree* tab = cria_hashT(tam);

     insereHash(tab, 10);
     insereHash(tab, 20);
     insereHash(tab, 30);
     insereHash(tab, 40);
     insereHash(tab, 50);
     insereHash(tab, 60);
     insereHash(tab, 70);
     insereHash(tab, 80);
     insereHash(tab, 10);

     imprime_escolhendo(tab, 1);
    return 0;
}
