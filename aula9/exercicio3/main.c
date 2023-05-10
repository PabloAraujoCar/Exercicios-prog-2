#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"


int main(){
    int qtd = 0, i, opcao;
    tPessoa *pessoas = alocaPonteiroPessoa();
    printf("Digite 1 para cadastrar novas pessoas e 0 para encerrar o programa \n");
    scanf("%d", &opcao);
    while(opcao == 1){
        printf("Digite os dados da %d° pessoa \n", qtd+1);
        lePessoa(pessoas, qtd);
        pessoas = realocaPonteiroPessoa(pessoas, qtd+1);
        qtd++;

        printf("Digite 1 para cadastrar novas pessoas e 0 para encerrar o programa \n");
        scanf("%d", &opcao);
    }

    for(i = 0; i < qtd; i++){
        printf("*********Dados da %d° pessoa*********\n", i+1);
        imprimePessoa(pessoas, i);
    }

    printf("Programa encerrado \n");
    liberaPessoa(pessoas);

    return 0;
}