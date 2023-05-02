#include <stdio.h>
#include <stdlib.h>
#include "cpf.h"


//cria um cpf com todos os  numeross prrenchidos com 0 e retorna um ponteiro que aponta para ele
tCPF *criaCPF(){
    int i;
    tCPF *cpf;
    cpf = (tCPF *) malloc(sizeof(tCPF));
    for(i = 0; i< 11; i++){
        cpf->digitos[i] = 0;
    }
    return cpf;
}

//Lê valores da entrada padrão e prrenche cpf
void leCPF(tCPF *cpf){
    int i, numero;
    char digito;

    for (i = 0; i < 11; i++){
        scanf("%c", &digito);
        while (digito < '0' || digito > '9'){
            scanf("%c", &digito);
        }
        numero = digito - '0';
        cpf->digitos[i] = numero;
    }
}

//Libera cpf
void liberaCPF(tCPF *cpf){
    free(cpf);
}

void imprimeCPF(tCPF *cpf){
    int i, j;
    for(i = 0; i <= 6; i += 3){
        for(j = 0; j <3; j++){
            printf("%d",cpf->digitos[i+j]);
        }
        printf(".");
    }
    printf("-%d%d", cpf->digitos[9], cpf->digitos[10]);
}