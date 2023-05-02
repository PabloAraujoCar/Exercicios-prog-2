#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"


int main(){
    int numAlunos, numAux, i, j;
    tAluno aux;
    tAluno *alunos;
    scanf("%d ", &numAlunos);
    alunos = (tAluno *) malloc( numAlunos * sizeof(tAluno));

    for (i = 0; i < numAlunos; i++){
        preencheAluno(&alunos[i]);
    }

    //odenando vetor alunos por ordem de matricula
    for (i = 0; i < numAlunos; i++){
        aux = alunos[i];
        numAux = i;
        for (j = i + 1; j < numAlunos; j++){
            if ( matricula2EhMenorQue1(aux, alunos[j]) ){
                aux = alunos[j];
                numAux = j;
            }
        }
        alunos[numAux] = alunos[i];
        alunos[i] = aux;
    }

    printf("Alunos Aprovados:\n");
    for(i = 0; i < numAlunos; i++){
        if( mediaDoAluno(alunos[i]) >= 7)
            imprimeNomeAluno(alunos[i]);
    }

    free(alunos);
    return 0;
}