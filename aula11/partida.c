#include <stdio.h>
#include <stdlib.h>
#include "partida.h"

struct partida{
    int time1;
    int time2;
    int gols_time1;
    int gols_time2;
};

partida* partida_construir(){
    partida *p;
    p = (partida *) malloc(sizeof(partida));
    if (p == NULL){
        printf("memoria insulficiente para alocar uma partida \n");
        exit(1);
    }
    return p;
}
void partida_ler(partida *p){
    scanf("%d", &p->time1);
    scanf("%d", &p->time2);
    scanf("%d", &p->gols_time1);
    scanf("%d", &p->gols_time2);
}
void partida_destruir(partida *p){
    free(p);
} 
int partida_jogou(partida *p, int time){
    if(time == p->time1 || time == p->time2){
        return 1;
    }
    return 0;
}
int partida_vencedor(partida *p){
    if(p->gols_time1 > p->gols_time2){
        return p->time1;
    }
    if(p->gols_time1 < p->gols_time2){
        return p->time2;
    }
    return -1;
}