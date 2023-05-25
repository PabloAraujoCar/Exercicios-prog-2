#ifndef _LESAO_H
#define _LESAO_H

typedef struct tLesao tLesao;

tLesao* alocaLesao ();
void leLesao(tLesao *lesao);
int retornaMalignidadeLesao(tLesao *lesao);
void imprimeIdLesao(tLesao *lesao);
void imprimeLesao(tLesao *lesao);
void liberaLesao(tLesao *lesao);

#endif