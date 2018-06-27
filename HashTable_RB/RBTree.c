#include <stdio.h>
#include <stdlib.h>
#include "RBTree.h"

Tree* criaTree(){
     Tree *RBTree = (Tree *) malloc(sizeof(Tree));
     RBTree->raiz = NULL;
     return RBTree;
}

NO* cria_no(int k){
    NO *no = (NO*)malloc(sizeof(NO));
    no->esq = no->dir = no->pai = NULL;
    no->info = k;
    no->cor = RED;
    return no;
}

void imprime_preorden(NO* raiz){
    //printf("<");
    if (raiz != NULL){
        printf("%d ", raiz->info);
        imprime_preorden(raiz->esq);
        imprime_preorden(raiz->dir);
    }
    //printf(">");
}

void imprime_inordem(NO* raiz){
    //printf("<");
    if (raiz != NULL){
        imprime_inordem(raiz->esq);
        printf("%d ", raiz->info);
        imprime_inordem(raiz->dir);
    }
    //printf(">");
}

void imprime_posordem(NO* raiz){
    //printf("<");
    if (raiz != NULL){
        imprime_posordem(raiz->esq);
        imprime_posordem(raiz->dir);
        printf("%d ", raiz->info);
    }
    //printf(">");
}

void imprime_escolhendo_orde(NO* raiz, int op){
    if (op == 1)
        imprime_preorden(raiz);
    else if (op == 2)
        imprime_inordem(raiz);
    else if (op == 3)
        imprime_posordem(raiz);
}

int verifica(NO* raiz){
    if (raiz->esq == NULL && raiz->dir == NULL){
        return 0;
    }
    if (raiz->esq != NULL && raiz->dir == NULL){
        return 1;
    }
    if (raiz->esq == NULL && raiz->dir != NULL){
        return 1;
    }
    if (raiz->esq != NULL && raiz->dir != NULL){
        return 2;
    }
}

void Rb_fix_up_insert(Tree* T, NO *Z){
    NO* y = NULL;
    while (Z != T->raiz && Z->pai->cor == RED){
        if (Z->pai->pai->esq == Z->pai){
            y = Z->pai->pai->dir;
            if (y != NULL && y->cor == RED){
                Z->pai->cor = BLACK;
                y->cor = BLACK;
                Z->pai->pai->cor = RED;
                Z = Z->pai->pai;
            }
            else{
                if (Z == Z->pai->dir){
                    Z = Z->pai;
                    LeftRotate(T, Z);
                }
                Z->pai->cor = BLACK;
                Z->pai->pai->cor = RED;
                RightRotate(T, Z->pai->pai);
            }

        }
        else{
            y = Z->pai->pai->esq;
            if (y != NULL && y->cor == RED){
                Z->pai->cor = BLACK;
                y->cor = BLACK;
                Z->pai->pai->cor = RED;
                Z = Z->pai->pai;
            }
            else{
                if (Z == Z->pai->esq){
                    Z = Z->pai;
                    RightRotate(T, Z);
                }
                Z->pai->cor = BLACK;
                Z->pai->pai->cor = RED;
                LeftRotate(T, Z->pai->pai);
            }
        }
    }
    T->raiz->cor = BLACK;
}

NO* Rb_insert(Tree* T, NO* Z){
    NO *y = NULL;
    NO *x = T->raiz;

    while (x != NULL){
        y = x;
        if (Z->info < x->info)
            x = x->esq;
        else
            x = x->dir;
    }

    Z->pai = y;

    if (y == NULL)
        T->raiz = Z;
    else if (Z->info < y->info)
        y->esq = Z;
    else
        y->dir = Z;

    Z->cor = RED;
    Z->esq = Z->dir = NULL;

    Rb_fix_up_insert(T, Z);

    return T->raiz;
}

void Rb_fix_up_remove(Tree* T, NO* Z){
    NO* p = NULL; //p = pai
    NO* i = NULL; //i = irmao
    if (Z->pai->esq == Z){

        p = Z->pai;
        i = Z->pai->dir;

        if (i->cor == RED) {
            i->cor = BLACK;
            p->cor = RED;
            LeftRotate(T, i);
        }

        if (i->cor == BLACK && p->cor == BLACK){
            i->cor = RED;
            Z = p;
            Rb_fix_up_remove(T, Z);
        }

        if (i->cor == BLACK && p->cor == RED && i->esq->cor == BLACK && i->dir->cor == BLACK){
            i->cor = RED;
            p->cor = BLACK;
        }

        if (i->cor == BLACK && i->esq->cor == RED && i->dir->cor == BLACK){
            i->esq->cor = BLACK;
            i->cor = RED;
            RightRotate(T, i);
            Rb_fix_up_remove(T, Z);
        }

        if (i->cor == BLACK && i->dir->cor == RED){
            i->cor = p->cor;
            p->cor = BLACK;
            i->dir = BLACK;
            LeftRotate(T, i);
        }

    }
    else{

        p = Z->pai;
        i = Z->pai->esq;

        if (i->cor == RED){
            i->cor = BLACK;
            p->cor = RED;
            RightRotate(T, i);
        }

        if (i->cor == BLACK && p->cor == BLACK){
            i->cor = RED;
            Z = p;
            Rb_fix_up_remove(T, Z);
        }

        if (i->cor == BLACK && p->cor == RED && i->dir->cor == i->esq->cor == BLACK){
            i->cor = RED;
            p->cor = BLACK;
        }

        if (i->cor == BLACK && i->dir->cor == RED && i->esq->cor == BLACK){
            i->dir->cor = BLACK;
            i->cor = RED;
            RightRotate(T, i);
            Rb_fix_up_remove(T, Z);
        }

        if (i->cor == BLACK && i->esq->cor == RED){
            i->cor = p->cor;
            p->cor = BLACK;
            i->esq = BLACK;
            LeftRotate(T, i);
        }
    }
}

NO* Rb_remove(Tree* T, NO* Z){
    while (Z!= NULL){
        NO* y = Z->pai;
        NO* x = Z;

        int opcode = verifica(x);

        if (opcode == 0) {
            if (y->esq == x)
                y->esq = NULL;
            else
                y->dir = NULL;
            free(x);
           Rb_fix_up_remove(T, y);
        }
        if (opcode == 1) {
            if (x->esq){
                NO* aux = x;
                x = x->esq;
                free(aux);
            } else{
                NO* aux2 = x;
                x = x->dir;
                free(aux2);
            }
        }
        if (opcode == 2){
            NO* p = x->esq;
            while (p->dir != NULL){
                p = p->dir;
            }
            x->info = p->info;
            p->info = Z->info;
            Z = p;
            y = Z->pai;
        }

    }
    return T->raiz;
}

void LeftRotate(Tree* T, NO* X){
    NO *y;

    y = X->dir;
    X->dir = y->esq;

    if (y->esq != NULL){
        y->esq->pai = X;
    }

    y->pai = X->pai;

    if (X->pai == NULL)
        T->raiz = y;

    else if (X->pai->esq == X){
        X->pai->esq = y;
    }

    else{
        X->pai->dir = y;
    }
    y->dir = X;
    X->pai = y;
}

void RightRotate(Tree* T, NO *X){
    NO *y;

    y = X->esq;
    X->esq = y->dir;

    if (y->dir != NULL)
        y->dir->pai = X;

    y->pai = X->pai;

    if (X->pai == NULL)
        T->raiz = y;

    else if (X->pai->dir == X){
        X->pai->dir = y;
    }

    else{
        X->pai->esq = y;
    }
    y->dir = X;
    X->pai = y;
}

NO* busca(NO *raiz, int k){
    if (raiz == NULL || raiz->info == k){
        return raiz;
    }

    else if (k < raiz->info){
        return busca(raiz->esq, k);
    }

    else{
        return busca(raiz->dir, k);
    }
}

void libera(Tree* T){
    libera_no(T->raiz);
    free(T);
}

void libera_no(NO *raiz){
    while(raiz != NULL){
        libera_no(raiz->esq);
        libera_no(raiz->dir);
        free(raiz);
    }
}
