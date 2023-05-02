#ifndef _ALUNO_H
#define _ALUNO_H

typedef struct{
    char nome[101];
    int matricula[3];
    int notas[3];
}tAluno;

void preencheAluno(tAluno *aluno);
void imprimeAluno(tAluno aluno);
void imprimeNomeAluno(tAluno aluno);
int matricula2EhMenorQue1(tAluno aluno1, tAluno aluno2);
int transformaMatriculaEmInt (tAluno aluno);
int mediaDoAluno (tAluno aluno);

#endif