#include <stdio.h>
#include <stdlib.h>
#include "time.h"

struct time{
    char nome[33];
    char estado[3];
};

time* time_construir(){
    time *t;
    t = (time *) malloc (sizeof(time));
    if(t == NULL){
        printf("Não tem memória sulficiente amigão \n");
        exit(1);
    }

    return t;
}
void time_ler(time *t){
    scanf("%s", t->nome);
    scanf("%s", t->estado);
}
void time_mostrar(time *t){
    printf("%s [%s]", t->nome, t->estado);
}
void time_destruir(time *t){
    free(t);
}