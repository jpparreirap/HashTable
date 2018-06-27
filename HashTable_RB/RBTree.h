#ifndef ARVORE_RB_H_INCLUDED
#define ARVORE_RB_H_INCLUDED

enum { BLACK, RED };

typedef struct no{
    int info;
    int cor;
    struct no* esq;
    struct no* dir;
    struct no* pai;
}NO;

typedef struct tree{
    NO* raiz;
    NO* sentinel;
}Tree;

Tree* criaTree();
NO* cria_no(int k);
void imprime_escolhendo_orde(NO* raiz, int op);
void imprime_preorden(NO* raiz);
void imprime_inordem(NO* raiz);
void imprime_posordem(NO* raiz);
int verifica(NO* raiz);
void Rb_fix_up_insert(Tree* T, NO *Z);
NO* Rb_insert(Tree* T, NO* Z);
void Rb_fix_up_remove(Tree* T, NO* Z);
NO* Rb_remove(Tree* T, NO* Z);
void LeftRotate(Tree* T, NO* X);
void RightRotate(Tree* T, NO *X);
NO* busca(NO *raiz, int k);
void libera(Tree* T);
void libera_no(NO *raiz);

#endif
