#include <stdio.h>
#include <stdlib.h>
#include "campeonato.h"
#include "partida.h"
#include "time.h"

struct campeonato{
   time **times;
   partida **partidas;

   int num_times;
   int num_partidas;
};

campeonato* campeonato_construir(){
    campeonato *camp;
    camp = (campeonato *) malloc(sizeof(campeonato));
    camp->times = (time **) malloc(sizeof(time **));
    camp->partidas = (partida **) malloc(sizeof(partida **));

    if(camp->partidas == NULL || camp->times == NULL){
        printf("Espaço de armazenamento insulficient para alocar times e partidas do campeonato \n");
        exit(1);
    }

    camp->num_times = 0;
    camp->num_partidas = 0;

    return camp; 
}

void campeonato_ler(campeonato *camp){
    char opcao = 'n';
    
    while(opcao != 'F' && opcao != 'f'){
        scanf("%c%*c", &opcao);
    
        if(opcao == 't' || opcao == 'T'){
            camp->times[camp->num_times] = time_construir();
            time_ler(camp->times[camp->num_times]);
            camp->num_times++;
            camp->times = realloc(camp->times, ((camp->num_times + 1) * sizeof(time *))  );
        }

        if(opcao == 'p' || opcao == 'P'){
            camp->partidas[camp->num_partidas] = partida_construir();
            partida_ler(camp->partidas[camp->num_partidas]);
            camp->num_partidas++;
            camp->partidas = realloc(camp->partidas, ((camp->num_partidas + 1) * sizeof(partida *)) );
        }
    }
}: le os dados de times e partidas
* campeonato_destruir: desaloca o campeonato
* campeonato_mostrar_relatorio: exibe na tela a pontuação por time
