#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "paciente.h"

struct tPaciente{
    char nome[101];
    tData* nascimento;
    char cartaoSus[19];
    char genero;
    tLesao **lesoes;
    int numLesoes;
};

tPaciente* alocaPaciente(){
    tPaciente *p;
    p = (tPaciente *) malloc(sizeof(tPaciente));
    return p;
}

void lePaciente(tPaciente *paciente){
    //printf("Digite o nome do paciente \n");
    scanf("%101[^\n]", paciente->nome);
    scanf("%*c"); //limpando buffer
    //printf("Digite data de nascimetno: \n");
    paciente->dataNacimento  = leData();
    scanf("%*c"); //limpando buffer
    //printf("Digite cartão sus \n");
    scanf("%19[^\n]", paciente->cartaoSus);
    scanf("%*c"); //limpando buffer
    //printf("Digite genero \n");
    scanf("%c", &paciente->genero);
    scanf("%*c");

    paciente->lesoes = (tLesao **) malloc(sizeof(tLesao*));
    paciente->numLesoes = 0;
    paciente->lesoes[0] = alocaLesao();
}


/*retorna 1 se o cartao do sus do paciente for compativel com o cartao esperado e 0 se não*/
int EhPacienteCerto(tPaciente *paciente, char cartaoSusEsperado[19]){
    if(strcmp(paciente->cartaoSus, cartaoSusEsperado) )
        return 0;
    return 1;
}

/*recebe um tPaciente e retorna ele com uma nova lesão cadastrada*/
void cadastraLesao(tPaciente *p){
    leLesao(p->lesoes[p->numLesoes]);
    p->numLesoes++;
    p->lesoes = (tLesao **) realloc(p->lesoes, (p->numLesoes + 1) * sizeof(tLesao *));
    p->lesoes[p->numLesoes] = alocaLesao();
}

int quantasLesoesPacienteTem (tPaciente *paciente){
    return paciente->numLesoes;
}

int retornaIdade(tPaciente *paciente){
    return calculaIdade(paciente->nascimento);
}

/*retorna 1 se o paciente tiver que ir pra cirurgia e 0 se não precisar*/
int pacientePrecisaCirurgia(tPaciente *paciente){
    int j;
    for (j = 0; j < paciente->numLesoes; j++){
        if (retornaMalignidadeLesao(paciente->lesoes[j]) > 50)
           return 1;
    }
    return 0;
}

void imprimePaciente(tPaciente *p){
    int i;
    printf("- %s - ", p->nome);
    //printf("data: %s \n", p.dataNacimento);
    //printf("cartao: %s \n", p.cartaoSus);
    //printf("genero: %c \n", p.genero);
    for(i = 0; i < p->numLesoes; i++){
        imprimeIdLesao(p->lesoes[i]);
    }
    printf("\n");
}

void liberaPaciente(tPaciente *p){
    int i;
    for(i = 0; i <= p->numLesoes; i++){
        liberaLesao(p->lesoes[i]);
    }
    free(p->lesoes);
    liberaData(p->nascimento);
    free(p);
}
