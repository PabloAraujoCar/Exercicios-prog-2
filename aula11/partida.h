#ifndef _PARTIDA_H
#define _PARTIDA_H

typedef struct partida partida;

partida* partida_construir();
void partida_ler(partida *p);
void partida_destruir(partida *p);
int partida_jogou(partida *p, int time);
int partida_vencedor(partida *p);

#endif