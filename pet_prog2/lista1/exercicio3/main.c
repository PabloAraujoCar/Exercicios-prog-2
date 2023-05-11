#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

int main(){
    int qtd = 0, i, opcao = 0, numContaA, numContaB;
    float valor;
    tConta *contas;
    contas = retornaPonteiroConta();

    while(opcao != -1){
        printf("\n********************************************************\n");
        printf("Selecione uma opção \n");
        printf(" 0 - sair \n 1 - saque \n 2 - depósito \n 3 - transferência \n");
        printf(" 4 - cadastro de usuário e conta \n 5 - relatório \n");
        scanf("%d", &opcao);

        switch (opcao){
            //SAIR
            case 0:
                opcao = -1;
                break;
            //SAQUE
            case 1:
                for(i = 0; i < qtd; i++){
                    imprimeContaSemSaldo(contas, i);
                }
                scanf("%d %f", &numContaA, &valor);
                saque(contas, qtd, numContaA, valor);

                //zerando valores pra não atrapalhar no futuro
                numContaA = -1;
                valor = 0;
                break;
            //DEPOSITO
            case 2:
                for(i = 0; i < qtd; i++){
                    imprimeContaSemSaldo(contas, i);
                }
                scanf("%d %f", &numContaA, &valor);
                deposito(contas, qtd, numContaA, valor);

                //zerando valores pra não atrapalhar no futuro
                numContaA = -1;
                valor = 0;
                break;
            //TRANSFERENCIA
            case 3:
                for(i = 0; i < qtd; i++){
                    imprimeContaSemSaldo(contas, i);
                }
                scanf("%d %d %f", &numContaA, &numContaB, &valor);
                transferencia(contas, qtd, numContaA, numContaB, valor);

                //zerando valores pra não atrapalhar no futuro
                numContaA = -1;
                numContaB = -1;
                valor = 0;
                break;
            //CADASTRAR NOVA CONTA
            case 4:
                leConta(contas, qtd);
                qtd++;
                contas = realocaPonteiroContas(contas, qtd + 1);
                break;
            //RELATORIO
            case 5:
                printf("===| Imprimindo Relatorio |=== \n");
                for (i = 0; i < qtd; i++){
                    imprimeContaCompleta(contas, i);
                    printf("\n");
                }
                break;
            default:
                break;
        }
    }
    liberaConta(contas, qtd);
    printf("************\n");
    printf("encerrando programa \n");
    printf("************\n");
    return 0;
}