#include "pessoa.h"
#include <stdlib.h>
struct tPessoa{
    char nome[101];
    char data[11];
    char CPF[15];
};

tPessoa* alocaPonteiroPessoa(){
    tPessoa *p;
    p = (tPessoa *) malloc(sizeof(tPessoa));
    return p;
}

tPessoa* realocaPonteiroPessoa(tPessoa *p, int tam){
    p = realloc(p, tam * sizeof(tPessoa));
    return p;
}

tPessoa lePessoa(){
    tPessoa pessoa;
    int i, num;
    scanf("%s", pessoa.nome);
    scanf("%s", pessoa.data);
    scanf("%s", pessoa.CPF);
    return pessoa;
}

void imprimePessoa(tPessoa *p){
    printf("%s \n", p->nome);
    printf("%s \n", p->data);
    printf("%s \n", p->CPF);
}