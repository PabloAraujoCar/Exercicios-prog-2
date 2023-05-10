#include "pessoa.h"
#include <stdlib.h>
#include <stdio.h>
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
    p = (tPessoa *) realloc(p, tam * sizeof(tPessoa));
    if (p == NULL){
        printf("ERRO, não tem mais memoria disponivel");
        exit(1);
    }
    return p;
}

void liberaPessoa(tPessoa *p){
    free(p);
}

void lePessoa(tPessoa *p, int num){
    printf("Digite o nome: ");
    scanf("%s", p[num].nome);
    printf("Digite a data de nascimento: ");
    scanf("%s", p[num].data);
    printf("Digite o CPF: ");
    scanf("%s", p[num].CPF);
}

void imprimePessoa(tPessoa *p, int num){
    printf("Nome: %s \n", p[num].nome);
    printf("Data: %s \n", p[num].data);
    printf("CPF: %s \n", p[num].CPF);
}

