#include "data.h"
#include <stdio.h>


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

int quantosDiasNoMes(tData data){
    int mes;
    mes = ano.mes;
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

tData criaData(int dia, int mes, int ano){
    tData data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;

    int maxDias;
    maxDias = quantosDiasNoMes(data);
    if(dia > maxDias){
        data.dia = maxDias;
    }
    
    if(mes < 1){
        printf(" \nErro, mês tem que estar entre 1 e 12");
        data.mes = 13 - mes;
    }
    if(mes > 12){
        printf(" \nErro, mês tem que estar entre 1 e 12");
        data.mes = 12 % 12;
    }
    if(dia < 1 || dia > 31){
        printf("\nErro, dia tem que estar entre 1 e 31");
        exit(1);
    }
    return data;
}
tData leData(){
    tData data;
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

int incrementaDia(tData){
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



int diferencaEntreDatas(tData data1, tData data2){
    int i;
}
Calcular a diferença em meses entre duas datas
Calcular a diferença em anos entre duas datas
Retornar nome do mês de uma data
Retornar se duas datas são iguais
