#ifndef _CONTA_H
#define _CONTA_H
typedef struct tConta tConta;

tConta* retornaPonteiroConta();
tConta* realocaPonteiroContas(tConta *conta, int tam);
void leConta(tConta *contas, int num);
void imprimeContaCompleta(tConta *contas, int num);
void imprimeContaSemSaldo(tConta *contas, int num);
int ehContaCerta(tConta conta, int num);
void saque(tConta *contas, int qtd, int num, int valor);
void deposito(tConta *contas, int qtd, int num, int valor);
void transferencia(tConta *contas, int qtd, int A, int B, int valor);
void liberaConta(tConta *contas, int qtd);

#endif