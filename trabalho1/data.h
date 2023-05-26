#ifndef _DATA_H
#define _DATA_H
 
typedef struct tData tData;

/*recebe 3 inteiros (dia, mes, ano) e retorna um tipo tData*/
tData* criaData(int dia, int mes, int ano);

/*Pede para o usuario digitar o dia, mes e ano e retorna o tData correspondente*/
tData* leData();

void imprimeData(tData *data);

/*recebe um tData e retorna a data do dia seguinte*/
void incrementaDia(tData* data);

/*retorna um tdata preenchido com a data do dia de hoje */
tData* dataHoje();

/*Recebe um tData e retorna 1 caso o ano seja bissexto*/
int ehBissexto(tData* data);

/*Recebe uma data e retorna o valor inteiro de dias no mês da data*/
int quantosDiasNoMes(tData* data);

/*Recebe dois tipos tData e retorna 1 se a primeira data for menor que a segunda e 0 se não for*/
int ehMenor(tData* data1, tData* data2);

/*recebe dois tDatas.Retorna 1 se as datas foram iguais e 0 se forem diferentes*/
int saoIguais(tData* data1, tData* data2);

/*Recebe duas datas e retorna o numero de dias entre elas*/
int diasEntreDatas(tData* data1, tData* data2);

int anosEntreDatas(tData* data1, tData* data2);

int calculaIdade(tData* nascimento);

void liberaData(tData* data);

#endif
