#include "pessoa.h"
#include <stdio.h>

int main(){
    tPessoa *pessoa1;
    pessoa1 = criaPessoa();
    preencheInformacoes(pessoa1);
    imprimePessoa(pessoa1);
    liberaPessoa(pessoa1);
    printf("aaaaaaaa");

    return 0;
}