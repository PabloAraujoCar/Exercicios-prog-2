#include <stdio.h>
#include <stdlib.h>

/******************Declarando funções***************************/

int VerificaSePrimo(int num);
int *criaVetor(int n);
void preencheVetorComPrimos(int *vetor, int tamanho);
void imprimeVetor(int *vetor, int tamanho);
void liberaVetor(int *vetor);

/******************Int Main***************************/

int main(){
    int n;
    int *numeros;
    scanf("%d", &n);
    numeros = criaVetor(n);
    preencheVetorComPrimos(numeros, n);
    imprimeVetor(numeros, n);

    liberaVetor(numeros);

    return 0;
}

/******************Definindo funções***************************/
int VerificaSePrimo(int num){
    int i;
    if(num == 2)
        return 1;
    for (i = 2; i < num; i++){
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int *criaVetor(int n){
    int *v = 0;
    if (n < 1){
        printf("Erro, inteiro menor que 1");
        exit(1);
    }

    v = (int *) malloc( n * sizeof(int));
    return v;
}

void preencheVetorComPrimos(int *vetor, int tamanho){
    int i, num;
    i = 0;
    num = 2;
    while (i < tamanho){
        if(VerificaSePrimo(num)){
            vetor[i] = num;
            i++;
        }
        num++;
    }
}

void imprimeVetor(int *vetor, int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
        printf("%d, ", vetor[i]);
    }
    printf(";");
}

void liberaVetor(int *vetor){
    free(vetor);
}