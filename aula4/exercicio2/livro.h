#ifndef _LIVRO_H
#define _LIVRO_H

typedef struct{
    char titulo[100];
    char autor[100];
    int anoPublicacao;
    int disponibilidade;
    int identificador;
}tLivro;

tLivro LIVCadastra (int identificador);
int LIVComparaTitulo(char* title, tLivro livro);
int LIVretornaIdentificador(tLivro livro);
void LIVimprimeLivro(tLivro livro);
int LIVverificaDisponibilidade(tLivro livro);
tLivro LIVdiminuiDisponibilidade(tLivro livro);
tLivro LIVaumentaDiponibilidade(tLivro livro);

#endif

