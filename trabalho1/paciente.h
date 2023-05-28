#ifndef _PACIENTE_H
#define _PACIENTE_H

#include "lesao.h"

typedef struct tPaciente tPaciente;


tPaciente* alocaPaciente();
void lePaciente(tPaciente *paciente);
void converterParaMaiuscula(char *string);
void lendoInfosConsulta(tPaciente* p);
int EhPacienteCerto(tPaciente *paciente, char cartaoSusEsperado[19]);
int ehMesmoPaciente(tPaciente* p1, tPaciente* p2);
void cadastraLesao(tPaciente *p);
int quantasLesoesPacienteTem (tPaciente *paciente);
int retornaIdade(tPaciente *paciente);
int pacientePrecisaCirurgia(tPaciente *paciente);
void imprimePaciente(tPaciente *p);
void liberaPaciente(tPaciente *p);

#endif