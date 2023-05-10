#ifndef _PESSOA_H
#define _PESSOA_H

typedef struct tPessoa tPessoa;

tPessoa* alocaPonteiroPessoa();
tPessoa* realocaPonteiroPessoa(tPessoa *p, int tam);
void liberaPessoa(tPessoa *p);
void lePessoa(tPessoa *p, int num);
void imprimePessoa(tPessoa *p, int num);


#endif