#ifndef _DATA_H
#define _DATA_H

typedef struct{
    int dia;
    int mes;
    int ano;
}tData;

int ehBissexto(tData data);
int quantosDiasNoMes(tData data);
tData criaData(int dia, int mes, int ano);
tData leData();
tData incrementaDia(tData data);
int ehMenor(tData data1, tData data2);
int saoIguais(tData data1, tData data2);
int diasEntreDatas(tData data1, tData data2);
void imprimeData(tData data);

#endif
