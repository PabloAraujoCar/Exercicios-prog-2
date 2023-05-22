#include <stdio.h>
#include "paciente.h"

int main(){
    tPaciente *pacientes = alocaPaciente();
    int qtdPac = 0, j, aux, teste;
    int mediaIdade = 0, qtdLesoes = 0, cirurgias = 0;
    char opcao = 'f';
    char cartaoAux[19];

    /************************Entrada************************/
    scanf("%c", &opcao);
    scanf("%*c");
    while (opcao != 'f' && opcao != 'F'){
        teste = 0;
        //printf("opcao = (%c) \n", opcao);
        if (opcao == 'p' || opcao == 'P'){
            //printf("Cadastrando paciente \n");
            lePaciente(pacientes, qtdPac);
            qtdPac++;
            pacientes = realocaPaciente(pacientes, qtdPac + 1);
        }
        if (opcao == 'l' || opcao == 'L'){
            //printf("Cadastrando lesão \n");
            scanf("%s%*c", cartaoAux);
            for(j = 0; j <= qtdPac; j++){
                if ( EhPacienteCerto(pacientes, j, cartaoAux) ){
                    teste = 1;
                    cadastraLesao(pacientes, j);
                }
            }
            if(teste == 0)
                printf("Cartão do sus não encontrado");
        }
        scanf("%c", &opcao);
        scanf("%*c");
    }
    //printf("opção = %c \n", opcao);

    
    /************************Calcula************************/

    //calculando média de idades e conta lesões
    for (j = 0; j < qtdPac; j++){
        mediaIdade += retornaIdade(pacientes, j);
        qtdLesoes += quantasLesoesPacienteTem(pacientes, j);
        cirurgias += pacientePrecisaCirurgia(pacientes, j);
    }
    mediaIdade = mediaIdade / qtdPac; 
    


    /************************Saída************************/
    printf("TOTAL PACIENTES: %d \n", qtdPac);
    printf("MEDIA IDADE (ANOS): %d \n", mediaIdade);
    printf("TOTAL LESOES: %d \n", qtdLesoes);
    printf("TOTAL CIRURGIAS: %d \n", cirurgias);
    printf("LISTA DE PACIENTES: \n");
    
    for (j = 0; j < qtdPac; j++){
        if(quantasLesoesPacienteTem(pacientes, j))
            imprimePaciente(pacientes, j);
    }
    
    liberaPaciente(pacientes, qtdPac);
    return 0;

}