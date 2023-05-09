#include <stdio.h>
#include <stdlib.h>
#define NUM_DISC 4
#define NUM_ALUN 3

/***************************declarando funções*******************************/
void freeNotas(int *notas);
void imprimeNotas(int *notas);

/***************************INT MAIN*******************************/

int main() {
    int *notas;
    int i, j, num;

    //alocando dinamicamente um único vetor para armazenar as notas
    notas = (int*)malloc(NUM_ALUN * NUM_DISC * sizeof(int));

    //lendo as notas da emtrada padrão
    for (i = 0; i < NUM_ALUN; i++){
        printf("Digite as notas do %d° aluno:", i+1);
        for (j = 0; j < NUM_DISC; j++){
            num = i * NUM_DISC + j;
            scanf("%d", &notas[num]);
        }

    }
    
    //imprimindo notas
    imprimeNotas(notas);

    //liberando toda memória alocada dinamicamente
    freeNotas(notas);
    return 0;
}

/***************************Definindo funções*******************************/
void freeNotas(int *notas){
    free(notas);
}

void imprimeNotas(int *notas){
    int i, j, num;
    for(i = 0; i < NUM_ALUN; i++){
        for(j = 0; j < NUM_DISC; j++){
            num = i * NUM_DISC + j;
            printf("  %d  ", notas[num]);
        }
        printf("\n");
    }
}