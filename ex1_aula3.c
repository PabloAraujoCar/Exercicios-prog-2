#include <stdio.h>
#include <string.h>
#define MAX_CONTAS 100

typedef struct{
    char nome[100];
    char cpf[11];
    char dataNascimento[10];
    char endereco[100];
    char Email[100];
    float saldo;
}tConta;

int main(){
    tConta contas[MAX_CONTAS];
    int i, op = 0;
    int num_contas = 0;

    do{
        while (op != 1 && op != 2 && op != 3 && op != 4 && op != 5){
            printf("Digite a ação que deseja agora \n");
            printf("1 - cadastrar nova conta \n");
            printf("2 - Inserir uma quantidade de dinheiro na conta de um cliente \n");
            printf("3 - Remover uma quantidade de dinheiro na conta de um cliente \n");
            printf("4 - Remover um cliente de agência \n");
            printf("5 - Encerrar operações \n")

            scanf("%d", &op);
            if (op != 1 && op != 2 && op != 3 && op != 4 && op != 5){
                printf("Opção inválida. \n Por favor digite uma opção válida \n");
            }
        }

        switch (op){
            case '1':
                contas[num_contas] = criarConta();
                num_contas = num_contas + 1;
                break;
            case '2':
                conta = inserirDinheiro(conta);
                break;
            case '3':
                conta = removerDinheiro(conta);
                break;
            case '4':
                a
                break;
            case '5':
                printf("operações encerradas \n");
        }
    }while (op != 5);

    return 0;
}

/**********************************************************************/
/*Funções do tipo tConta*/
tConta criarConta(){
    int i;
    char c = 'a';
    float f;
    tConta conta;

    printf("Digite o nome do titular da conta\n");
    for (i = 0; c != '\0'; i++){
        scanf("%c", &c);
        conta.nome[i] = c;
    }

    printf("Digite o cpf do titular da conta, apenas números\n");
    for (i = 0; c != '\0'; i++){
        scanf("%c", &c);
        conta.cpf[i] = c;
    }

    printf("Digite a data de nascimento do titular da conta, no formato dd/mm/aaaa\n");
    for (i = 0; c != '\0'; i++){
        scanf("%c", &c);
        conta.dataNascimento[i] = c;
    }

    printf("Digite o endereço do titular da conta\n");
    for (i = 0; c != '\0'; i++){
        scanf("%c", &c);
        conta.endereco[i] = c;
    }

    printf("Digite o Email do titular da conta\n");
    for (i = 0; c != '\0'; i++){
        scanf("%c", &c);
        conta.Email[i] = c;
    }

    printf("Digite o saldo inicial da conta\n");
    scanf("%f", &f);
    conta.saldo = f;

    return conta;
}

tConta inserirDinheiro(tConta conta){
    printf("Digite quando deseja inserir na conta \n");
    scanf("%f", &f);
    conta.saldo = conta.saldo + f;
    return conta;
}

tConta removerDinheiro(tConta conta){
    printf("Digite quando deseja remover na conta \n");
    scanf("%f", &f);
    conta.saldo = conta.saldo - f;
    return conta;
}

tConta achaContaPeloCPF (tConta *contas, char *cpf){
    int i, aux;
    tConta contaProcurada;
    for (i = 0; i < MAX_CONTAS; i++){
        aux = strcmp(contas[i], cpf);
        if (aux == 0){
            contaProcurada = contas[i];
            break;
        }
    }
    /*se ao final do laço nenhuma conta possui o cpf informado então não tem oq fazer*/
    if (aux != 0){
        printf("conta não encontrada\n");
        exit(1);
    }
    return contaProcurada  


    ;
}