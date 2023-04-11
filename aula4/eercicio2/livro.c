#include <stdio.h>
#include <string.h>
#include "livro.h"

/*Inicia um tipo tLivro*/
tLivro LIVCadastra (int identificador){
    tLivro livro;
    printf("Digite o titulo do livro \n");
    scanf(" %100[^\n]", livro.titulo);
    prinf("Digite o nome do autor do livro \n");
    scanf(" %100[^\n]", livro.autor);
    printf("Digite o ano de publicação do livro \n");
    scanf("%d", &livro.anoPublicacao);
    printf("Digite quanos exemplares do livro estão disponiveis \n");
    scanf("%d", &livro.disponibilidade);
    livro.identificador = identificador;
    return Livro;
}

/*Recebe uma string e um tipo tLivro e retorna 0 caso a string seja exatamente igual ao titulo do livro*/
int LIVComparaTitulo(char* title, tLivro livro){
    int teste;
    teste = strcmp(title, livro.titulo);
    return teste;
}

int LIVretornaIdentificador(tLivro livro){
    return livro.identificador;
}

void LIVimprimeLivro(tLivro livro){
    printf("%s \n", livro.titulo);
    printf("    ");
    printf("Autor: %s \n", livro.autor);
    printf("    ");
    printf("Ano de publicação: %d \n", livro.anoPublicacao);
    printf("    ");
    printf("Exemplares disponiveis: %d \n", livro.disponibilidade);
    printf("    ");
    printf("Identificador único: %d \n", livro.identificador);
}

int LIVverificaDisponibilidade(tLivro livro){
    return livro.disponibilidade;
}

tLivro LIVdiminuiDisponibilidade(tLivro livro){
    livro.disponibilidade--;
    return livro;
}

tLivro LIVaumentaDiponibilidade(tLivro livro){
    livro.disponibilidade++;
    return livro;
}

