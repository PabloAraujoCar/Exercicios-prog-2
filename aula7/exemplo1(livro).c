#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[101];
    char autor[101];
    int edicao;
    int numPag;
}tLivro;

void criaLivro (tLivro *livro);
void imprimeLivro (tLivro livro);

int main(){
    tLivro livro1;

    criaLivro(&livro1);
    imprimeLivro(livro1);


    return 0;
}


void criaLivro (tLivro *livro){
    printf("Digite titulo \n");
    fgets(livro->nome, 101, stdin);
    printf("Digite autor \n");
    scanf("%101[^\n]", livro->autor);
    printf("Digite edição \n");
    scanf(" %d", &livro->edicao);
    printf("Digite numero de páginas \n");
    scanf(" %d", &livro->numPag);
}

void imprimeLivro (tLivro livro){
    printf("\n***********************\n");
    printf("Titulo: %s", livro.nome); //fgets adiciona o \n na string, então não precisa do \n aqui de novo
    printf("Autor: %s \n", livro.autor);
    printf("Edição: %d \n", livro.edicao);
    printf("numero de páginas: %d \n", livro.numPag);
}
