#include <stdio.h>
#include <stdlib.h>
#include "campeonato.h"
#include "partida.h"
#include "time.h"

struct campeonato{
   time **times;
   partida **partidas;
};

campeonato* campeonato_construir(){
    campeonato *camp;
    camp = (campeonato *) malloc(sizeof(campeonato));
    camp->times = NULL;
    camp->partidas = NULL;

    return camp; 
}: aloca espaço para um campeonato e inicializa variáveis, se necessário.

void campeonato_ler(campeonato *camp){
    
}: le os dados de times e partidas
* campeonato_destruir: desaloca o campeonato
* campeonato_mostrar_relatorio: exibe na tela a pontuação por time
