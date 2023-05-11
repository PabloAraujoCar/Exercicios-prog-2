#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "conta.h"

struct tConta{
    tUsuario *user;
    int conta;
    float saldo;
};

//retorna um ponteiro do tipo tConta
tConta* retornaPonteiroConta(){
    tConta *conta;
    conta = (tConta *) malloc (sizeof(tConta));
    if(conta == NULL){
        printf("Não há espaço na memória para armazenar o vetor contas");
        exit(1);
    }
    return conta;
}

//recebe um ponteiro do tipo tConta e um inteiro N como parametro e 
//retorna o endereço do ponteiro realoca pra caber N contas 
tConta* realocaPonteiroContas(tConta *conta, int tam){
    conta = (tConta *) realloc(conta, tam * sizeof(tConta));
    if(conta == NULL){
        printf("Não há espaço na memória para armazenar o vetor contas");
        exit(1);
    }
    return conta;
}

//recebe um ponteiro do tipo tConta e preencher ele com informações da entrada padrão
void leConta(tConta *contas, int num){
    printf("Digite os dados do usuario e da conta \n");
    contas[num].user = retornaPonteiroUsuario();
    leUsuario(contas[num].user);
    scanf("%d", &contas[num].conta);
}

//recebe um vetor do tipo tConta e um inteiro N e imprime a [N+1]ª conta do vetor
void imprimeContaCompleta(tConta *contas, int num){
    printf("Conta: %d \n", contas[num].conta);
    printf("saldo: R$ %.2f \n", contas[num].saldo);
    imprimeUsuario(contas[num].user);
}

//recebe um vetor de contas e um numero e imprime o 
//numero da [N + 1]ª conta e o nome do portador dela
void imprimeContaSemSaldo(tConta *contas, int num){
    printf("Conta: %d \n", contas[num].conta);
    imprimeSoNomeUser(contas[num].user);
}

//recebe uma conta C e um numero N e 
//retorna 1 se o numero N for igual ao numero da conta C e 0 se não for igual
int ehContaCerta(tConta conta, int num){
    if (conta.conta == num)
        return 1;
    return 0;
}

//recebe um vetor de contas, a quantidade qtd de contas no vetor, um inteiro N e um valor V e
// retira da conta de numero N o valor V
void saque(tConta *contas, int qtd, int num, int valor){
    int i;
    for(i = 0; i < qtd; i++){
        if ( ehContaCerta(contas[i], num) ){
            if( contas[i].saldo >= valor ){
                contas[i].saldo -= valor;
            }else{
                printf("Saldo insulficinete! \n");
            }
            break;
        }
    }
}

//recebe um vetor de contas, a quantidade qtd de contas no vetor, um inteiro N e um valor V e
//adiciona na conta de numero N o valor V
void deposito(tConta *contas, int qtd, int num, int valor){
    int i;
    for(i = 0; i < qtd; i++){
        if ( ehContaCerta(contas[i], num) ){
            contas[i].saldo += valor;
            break;
        }
    }
}

//recebe um vetor de contas, a quantidade qtd de contas no vetor, dois numeros inteiros A e B  e um valor V,
//retira da conta de numero A o valor V e adiciona esse valor V na conta de numero B
void transferencia(tConta *contas, int qtd, int A, int B, int valor){
    int i, numA = -1, numB = -1;
    for(i = 0; i < qtd; i++){
        if ( ehContaCerta(contas[i], A) )
            numA = A;
        if ( ehContaCerta(contas[i], B))
            numB = B;
    }
    if (numA != -1 && numB != -1){
        if (contas[numA].saldo >= valor){
            contas[numA].saldo -= valor;
            contas[numB].saldo += valor;
        }else{
            printf("O saldo da conta %d insulficiente \n", numA);
        }
    }else{
        if (numA == -1)
            printf("O numero %d não corresponde ao numero de nehuma conta cadastrada", A);
        if (numB == -1)
            printf("O numero %d não corresponde ao numero de nehuma conta cadastrada", B);
    }
}

void liberaConta(tConta *contas, int qtd){
    int i;
    //primeiro é necessário liberar cada usuario em cada conta, depois se usa o free no vetor contas
    for (i = 0; i < qtd; i++){
        liberaUsuario(contas[i].user);
    }
    free(contas);
}