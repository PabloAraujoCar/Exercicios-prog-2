#include <stdio.h>
#include <stdlib.h>
#define NUM_DISC 4
#define NUM_ALUN 3

/***************************declarando funções*******************************/
void freeNotas(int **notas);
void imprimeNotas(int **notas);

/***************************INT MAIN*******************************/

int main() {
    int **notas;
    int i, j;
    //alocando dinamicamente as linhas e colunas da matrix 
    notas = (int**)malloc(NUM_ALUN*sizeof(int*));

    for(int j=0; j<NUM_ALUN; j++) {
        notas[j] = (int*)malloc(NUM_DISC*sizeof(int));
    }

    //lendo as notas da emtrada padrão
    for (i = 0; i < NUM_ALUN; i++){
        printf("Digite as notas do %d° aluno:", i+1);
        for (j = 0; j < NUM_DISC; j++){
            scanf("%d", &notas[i][j]);
        }

    }
    
    //imprimindo notas
    imprimeNotas(notas);

    //liberando toda memória alocada dinamicamente
    freeNotas(notas);
    return 0;
}

/***************************Definindo funções*******************************/
void freeNotas(int **notas){
    int i;
    for (i = 0; i < NUM_ALUN; i++){
        free(notas[i]);
    }
    free(notas);
}

void imprimeNotas(int **notas){
    int i, j;
    for(i = 0; i < NUM_ALUN; i++){
        for(j = 0; j < NUM_DISC; j++){
            printf("  %d  ", notas[i][j]);
        }
        printf("\n");
    }
}