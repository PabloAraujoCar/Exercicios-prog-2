#ifndef _TIME_H
#define _TIME_H

typedef struct time time;

time* time_construir();
void time_ler(time *t);
void time_mostrar(time *t);
void time_destruir(time *t);

#endif