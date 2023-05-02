#ifndef _CPF_H
#define _CPF_H

typedef struct{
    int digitos[11];
}tCPF;

tCPF *criaCPF();
void leCPF(tCPF *cpf);
void liberaCPF(tCPF *cpf);
void imprimeCPF(tCPF *cpf);

#endif