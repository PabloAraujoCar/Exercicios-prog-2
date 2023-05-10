#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

struct tUsuario{
    char nome[101];
    char cpf[15];
};

tUsuario* retornaPonteiroUsuario(){
    tUsuario *u;
    u = (tUsuario *) malloc(sizeof(tUsuario));
    return u;
}

void leUsuario(tUsuario *user){
    scanf("%101[^\n]", user->nome);
    scanf("%15[^\n]", user->cpf);
}

void imprimeUsuaraio(tUsuario *user){
    printf("Nome: %s \n", user->nome);
    printf("CPF: %s \n", user->cpf);
}