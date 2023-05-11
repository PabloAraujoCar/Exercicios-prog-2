#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

int main(){
    int qtd = 0, i, opcao, numContaA, numContaB;
    float valor;
    tConta *contas;
    contas = retornaPonteiroConta();
    contas = realocaPonteiroContas(contas, 2);

    for (qtd = 0; qtd < 2; qtd++){
        leConta(contas, qtd);
    }

    printf("\n===| Imprimindo Relatorio |===\n");
    for (qtd = 0; qtd < 2; qtd++){
        imprimeContaCompleta(contas, qtd);
        printf("\n");
    }
    liberaConta(contas, qtd);

    return 0;
}