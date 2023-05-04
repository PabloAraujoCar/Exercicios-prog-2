#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[101];
    char data[10];
    char CPF[14];
}tPessoa;

tPessoa lePessoa();
void imprimePessoa(tPessoa pessoa);

/***************************************************************/
int main(){
    int i, opcao, qtd = 0;
    tPessoa *pessoas;
    pessoas = (tPessoa *) malloc(sizeof(tPessoa));

    printf("Digite 1 para cadastrar mais uma pessoa e 0 para encerrar \n");
    scanf("%d", &opcao);

    while(opcao == 1){
        printf("Digite os dados de uma pessoa \n");
        pessoas[qtd] = lePessoa();
        qtd++;
        pessoas = realloc(pessoas, (qtd + 1) * sizeof(tPessoa));
        scanf("%d", &opcao);
    }
    for(i = 0; i < qtd; i++){
        imprimePessoa(pessoas[i]);
    }

    return 0;
}

/***************************************************************/
tPessoa lePessoa(){
    tPessoa pessoa;
    int i, num;
    scanf("%s", pessoa.nome);
    scanf("%s", pessoa.data);
    scanf("%s", pessoa.CPF);
    return pessoa;
}

void imprimePessoa(tPessoa p){
    printf("%s \n", p.nome);
    printf("%s \n", p.data);
    printf("%s \n", p.CPF);
}
