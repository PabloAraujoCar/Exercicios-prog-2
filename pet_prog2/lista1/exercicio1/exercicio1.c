#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

/************Declarando funções************/
void calcula_esfera (float R, float* area, float* volume);
void imprime_esfera (float R, float area, float volume);

/************Int Main************/

int main(){
    float raio, A, V;
    float *area, *volume;
    area = &A;
    volume = &V;
    printf("Digite o valor do raio da esfera: \n");
    scanf("%f", &raio);
    calcula_esfera(raio, area, volume);
    imprime_esfera(raio, *area, *volume);

    return 0;
}

/************Definindo Funções************/
void calcula_esfera (float R, float *area, float *volume){
    *area = 4 * PI * R * R; 
    *volume = (4/3) * PI * R * R * R;
}

void imprime_esfera (float R, float area, float volume){
    printf("Esfera de raio: %.2f -> area: %.2f | volume: %.2f \n", R, area, volume);
}