#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

void preencheAluno(tAluno *aluno){
    char c;
    int i, num;
    scanf("%s ", aluno->nome); //preenchendo nome
    while(c < '0' || c > '9'){      //preenchendo matricula
        scanf("%c", &c);
    }
    for(i = 0; i < 3; i++){
        num = c - '0';
        aluno->matricula[i] = num;
        scanf("%c", &c);
    }
    for(i = 0; i < 3; i++){
        scanf(" %d", &num);
        aluno->notas[i] = num;
    }
}

void imprimeAluno(tAluno aluno){
    int i;
    printf("%s \n", aluno.nome);
    for(i = 0; i < 3; i++){
        printf("%d", aluno.matricula[i]);
    }
    printf("\n");
    for(i = 0; i < 3; i++){
        printf("%d", aluno.notas[i]);
    }
    printf("\n");
}

void imprimeNomeAluno(tAluno aluno){
    printf("%s\n", aluno.nome);
}

int matricula2EhMenorQue1(tAluno aluno1, tAluno aluno2){
    int mat1, mat2;
    mat1 = transformaMatriculaEmInt(aluno1);
    mat2 = transformaMatriculaEmInt(aluno2);

    if (mat2 < mat1)
        return 1;
    return 0;
}

int transformaMatriculaEmInt (tAluno aluno){
    int numMatricula = 0;
    numMatricula += 100 * aluno.matricula[0];
    numMatricula += 10 * aluno.matricula[1];
    numMatricula += aluno.matricula[2];

    return numMatricula;
}

int mediaDoAluno (tAluno aluno){
    int i, media = 0;
    for(i = 0; i<3; i++){
        media += aluno.notas[i];
    }
    media = media / 3;
}