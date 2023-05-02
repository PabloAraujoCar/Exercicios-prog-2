#include "pessoa.h"
#include <stdlib.h>
#include <stdio.h>


tPessoa *criaPessoa(){
    tPessoa *pessoa;
    pessoa = (tPessoa *) malloc(sizeof(tPessoa));
    return pessoa;
}

void preencheInformacoes(tPessoa *pessoa){
    printf("Digite o nome: \n");
    scanf("%101[^\n]", pessoa->nome);
    pessoa->cpf = criaCPF();
    printf("Digite o CPF: \n");
    leCPF(pessoa->cpf);
    printf("Digite a data de nascimento: \n");
    pessoa->data = leData();
}

void imprimePessoa(tPessoa *pessoa){
    printf("Nome: %s \n", pessoa->nome);
    printf("Data de nascimento: ");
    imprimeData(pessoa->data);
    printf("\nCPF: ");
    imprimeCPF(pessoa->cpf);
    printf("\n");
}

//libera mémoria alocada
void liberaPessoa(tPessoa *pessoa){
    liberaCPF(pessoa->cpf);
    free(pessoa);
}