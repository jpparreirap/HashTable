#include <stdio.h>
#include <stdbool.h>
#include "HashStr.h"

int main() {
    int tam;

    HASHStr *str = cria_hashT(11);

    str = insereHash(str, "jp");
    str = insereHash(str, "test");
    str = insereHash(str, "lfadj");
    imprimeHash(str);


    liberaHash(str);
    return 0;
}
