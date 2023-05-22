#include <stdio.h>
#include <stdlib.h>
#include "lesao.h"

struct tLesao{
    char identificador[11];
    char diagnostico[101];
    char regiao[101];
    int malignidade;
};

//aloca um vetor lesão e retorna o ponteiro pra ele
tLesao* alocaLesao (){
    tLesao *lesao;
    lesao = (tLesao *) malloc(sizeof (tLesao));

    return lesao;
}

//recebe um vetor lesão e um inteiro N e preenche a [N-1]ª lesão com as informações da entrada padrão
void leLesao(tLesao *lesao){
    //printf("Digite o id da lesão \n");
    scanf("%11[^\n]%*c", lesao->identificador);
    //printf("Digite diagnostico da lesão \n");
    scanf("%101[^\n]%*c", lesao->diagnostico);
    //printf("Digite região da lesão \n");
    scanf("%101[^\n]%*c", lesao->regiao);
    //printf("Digite a malignidade da lesão \n");
    scanf("%d%*c", &lesao->malignidade);

}

/*retorna 1 se uma função estiver vazia e 0 se não estiver*/
int verificaSeLesaoVazia(tLesao *lesao){
    if(lesao->malignidade < 0)
        return 1;
    return 0;
}

/*retorna malignidade da lesão*/
int retornaMalignidadeLesao(tLesao *lesao){
    return lesao->malignidade;
}

/*imprime identificador unico da lesão*/
void imprimeIdLesao(tLesao *lesao){
    printf("%s ", lesao->identificador);
}

void imprimeLesao(tLesao *lesao){
    printf("identificador: %s \n", lesao->identificador);
    printf("Diagnostico: %s \n", lesao->diagnostico);
    printf("regiao: %s \n", lesao->regiao);
    printf("malignidade: %d \n", lesao->malignidade);
}

void liberaLesao(tLesao *lesao){
    free(lesao);
}
