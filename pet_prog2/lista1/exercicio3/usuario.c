#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

struct tUsuario{
    char nome[101];
    char cpf[15];
};

//retorna um ponteiro do tipo tUsuario
tUsuario* retornaPonteiroUsuario(){
    tUsuario *user;
    user = (tUsuario *) malloc(sizeof(tUsuario));
    return user;
}

//recebe um ponteiro do tipo tUsuario como parametro e 
//preenche ele com informações lidas da entrada padrão
void leUsuario(tUsuario *user){
    //printf("Digite o nome do usuario e o CPF: \n");
    scanf("%*c%101[^' ']%*c", user->nome);
    scanf("%15[^' ']", user->cpf);
}

//recebe um ponteiro do tipo tUsuario como parametro e imprime as informações dele
void imprimeUsuario(tUsuario *user){
    printf("Nome: %s \n", user->nome);
    printf("CPF: %s \n", user->cpf);
}

void imprimeSoNomeUser(tUsuario *user){
    printf("Nome: %s \n", user->nome);
}

void liberaUsuario(tUsuario *user){
    free(user);
}