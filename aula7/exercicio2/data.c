#include "data.h"
#include <stdio.h>

/*definindo funçoes de um TAD para manipular datas 
Pablo Araujo Carvalho
feito: 04/04/2023
refeito 30/04/2023*/

/*Recebe um tData e retorna 1 caso o ano seja bissexto*/
int ehBissexto(tData data){
    int div4, div100, div400;
    div4 = data.ano % 4;
    div100 = data.ano % 100;
    div400 = data.ano % 400;

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
int quantosDiasNoMes(tData data){
    int mes;
    mes = data.mes;
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

/*recebe 3 inteiros (dia, mes, ano) e retorna um tipo tData*/
tData criaData(int dia, int mes, int ano){
    tData data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;

    int maxDias;
    maxDias = quantosDiasNoMes(data);
    
    if(mes < 1)
        data.mes = 1;
    if(mes > 12)
        data.mes = 12;
    if(dia < 1)
        data.dia = 1;
    if(dia > 31)
    if(dia > maxDias)
        data.dia = maxDias;

    return data;
    
}

/*Pede para o usuario digitar o dia, mes e ano e retorna o tData correspondente*/
tData leData(){
    tData data;
    int dia, mes, ano;
    scanf ("%d/%d/%d", &dia, &mes, &ano);

    data = criaData(dia, mes, ano);
    return data;
}

/*recebe um tData e retorna a data do dia seguinte*/
tData incrementaDia(tData data){
    int maxDias;
    maxDias = quantosDiasNoMes(data);

    data.dia++;
    if (data.dia > maxDias){
        data.dia = 1;
        data.mes++;
        if(data.mes > 12){
            data.mes = 1;
            data.ano++;
        }
    }

    return data;
}

/*Recebe dois tipos tData e retorna 1 se a primeira data for menor que a segunda e 0 se não for*/
int ehMenor(tData data1, tData data2){
    if (data1.ano < data2.ano)
        return 1;
    if (data2.ano < data1.ano)
        return 0;
    //caso os anos sejam iguais, testamos os meses
    if(data1.mes < data2.mes)
        return 1;
    if (data2.mes < data1.mes)
        return 0;
    //caso os meses sejam iguais tambem, testamos os dias
    if (data1.dia < data2.dia)
        return 1;
    else
        return 0;
}

/*recebe dois tDatas.Retorna 1 se as datas foram iguais e 0 se forem diferentes*/
int saoIguais(tData data1, tData data2){
    if(data1.ano == data2.ano){
        if(data1.mes == data2.mes){
            if(data1.dia == data2.dia){
                return 1;
            }
        }
    }
    return 0;
}

/*Recebe duas datas e retorna o numero de dias entre elas*/
int diasEntreDatas(tData data1, tData data2){
    int i = 0;
    tData aux;
    //garantindo que a data 1 seja a menor das duas
    if (ehMenor(data2, data1)){
        aux = data2;
        data2 = data1;
        data1 = aux;
    }
    while ( !saoIguais(data1, data2) ){
        i++;
        data1 = incrementaDia(data1);
    }
    return i;
}

void imprimeData(tData data){
    printf("%d/", data.dia);
    if (data.ano < 10)
        printf("0%d/", data.mes);
    else   
        printf("%d", data.mes);
    printf("%d",data.ano);
}