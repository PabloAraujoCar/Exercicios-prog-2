#ifndef _PESSOA_H
#define _PESSOA_H

#include "cpf.h"
#include "data.h"

typedef struct{
    char nome[101];
    tCPF *cpf;
    tData data;
}tPessoa;


tPessoa *criaPessoa();
void preencheInformacoes(tPessoa *pessoa);
void imprimePessoa(tPessoa *pessoa);
void liberaPessoa(tPessoa *pessoa);
#endif