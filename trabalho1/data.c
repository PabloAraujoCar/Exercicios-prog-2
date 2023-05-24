#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"

struct tData{
  int dia;
  int mes;
  int ano;
};

/*recebe 3 inteiros (dia, mes, ano) e retorna um tipo tData*/
tData* criaData(int dia, int mes, int ano){
    tData* data;
    data = (tData*) malloc(sizeof(tData));
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;

    int maxDias;
    maxDias = quantosDiasNoMes(data);
    if(dia > maxDias){
        data->dia = maxDias;
    }
    
    if(mes < 1){
        printf(" \nMês tem que estar entre 1 e 12");
        while(data->mes < 1){
          data->mes = 13 - mes;
        }
    }
    if(mes > 12){
        printf(" \nMês tem que estar entre 1 e 12");
        data->mes = 12 % 12;
    }
    if(dia < 1 || dia > 31){
        printf("\nDia tem que estar entre 1 e 31");
        exit(1);
    }
    return data;
    
}

/*Pede para o usuario digitar o dia, mes e ano e retorna o tData correspondente*/
tData* leData(){
    tData* data;
    int dia, mes, ano;
    printf("Digite o dia \n");
    scanf ("%d", &dia);
    printf("Digite o mês no formato \n")
    scanf("%d", &mes);
    printf("Digite o ano \n");
    scanf("%d", &ano);

    data = criaData(dia, mes, ano);
    return data;
}

/*recebe um tData e retorna a data do dia seguinte*/
void incrementaDia(tData* data){
    int maxDias;
    maxDias = quantosDiasNoMes(data);

    data->dia++;
    if (data->dia > maxDias){
        data->dia = 1;
        data->mes++;
        if(data->mes > 12){
            data->mes = 1;
            data->ano++;
        }
    }
}

/*retorna um tdata preenchido com a data do dia de hoje */
tData* dataHoje(){
    tData* hoje;
    time_t agora;
    struct tm* timeHoje;
  
    hoje = malloc(sizeof(tData));
    time(&agora);
    timeHoje = localtime(&agora);
  
    hoje->dia = timeHoje->tm_mday;
    hoje->mes = timeHoje->tm_mon + 1;
    hoje->ano = timeHoje->tm_year + 1900;
  
    return hoje;
}

/*Recebe um tData e retorna 1 caso o ano seja bissexto*/
int ehBissexto(tData* data){
    int div4, div100, div400;
    div4 = data->ano % 4;
    div100 = data->ano % 100;
    div400 = data->ano % 400;

    if ( !div4 ){
        if( !div100){
            if( !div400 ){
                return 1;
            }else {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

/*Recebe uma data e retorna o valor inteiro de dias no mês da data*/
int quantosDiasNoMes(tData* data){
    int mes;
    mes = data->mes;
    if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        return 30;
    }else{
        if (mes == 2){
            if (ehBissexto(data)){
                return 29;
            }else return 28;
        }
        return 31;
    }
}

/*Recebe dois tipos tData e retorna 1 se a primeira data for menor que a segunda e 0 se não for*/
int ehMenor(tData* data1, tData* data2){
    if (data1->ano < data2->ano)
        return 1;
    if (data2->ano < data1->ano)
        return 0;
    //caso os anos sejam iguais, testamos os meses
    if(data1->mes < data2->mes)
        return 1;
    if (data2->mes < data1->mes)
        return 0;
    //caso os meses sejam iguais tambem, testamos os dias
    if (data1->dia < data2->dia)
        return 1;
    else
        return 0;
}

/*recebe dois tDatas.Retorna 1 se as datas foram iguais e 0 se forem diferentes*/
int saoIguais(tData* data1, tData* data2){
    if(data1->ano == data2->ano){
        if(data1->mes == data2->mes){
            if(data1->dia == data2->dia){
                return 1;
            }
        }
    }
    return 0;
}

/*Recebe duas datas e retorna o numero de dias entre elas*/
int diasEntreDatas(tData* data1, tData* data2){
    int i = 0;
    tData aux, d1, d2;
    d1 = *data1;
    d2 = *data2;
    //garantindo que a data 1 seja a menor das duas
    if (ehMenor(&d2, &d1)){
        aux = d2;
        d2 = d1;
        d1 = aux;
    }
    while ( !saoIguais(&d1, &d2) ){
        i++;
        incrementaDia(&d1);
    }
    return i;
}

int anosEntreDatas(tData* data1, tData* data2){
     int i = 0;
     tData aux, d1, d2;
     d1 = *data1;
     d2 = *data2;
    //garantindo que a data 1 seja a menor das duas
    if (ehMenor(&d2, &d1)){
        aux = d2;
        d2 = d1;
        d1 = aux;
    }
    while(d1.ano <= d2.ano){
        if(d1.dia<= d2.dia && d1.mes <= d2.mes){
            i++;
        }else{
            break;
        }
    }
  return i;
}

int idade(tData* nascimento){
    int i = 0;
    tData* hoje;
    hoje = dataHoje();
    if(ehMenor(nascimento, hoje){
        i = anosEntreDatas(nascimento, hoje);
    }else{
        printf("nascimento tem que anteceder o dia de hoje");
        return -1;
    }
  
    liberaData(hoje);
}

void liberaData(tData* data){
    free(data);
}
