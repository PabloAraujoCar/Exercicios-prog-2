#include "paciente.h"
#include "miniSADE.h"

struct miniSade{
    tPaciente** pacientes;
    int qtdPacientes;
};

miniSade iniciaSade(){
    miniSade* sade;
    //alocando espaço pra guardar um sade
    sade = (miniSade *) malloc(sizeof(miniSade));

    //alocando espaço pra guardar uma lista(vetor) de ponteiros que apontam para pacientes 
    sade->pacientes = (tPaciente **) malloc(sizeof(tPaciente *));

    //alocando espaço para o primeiro paciente da lista
    sade->pacientes[0] = alocaPaciente();

    sade->qtdPacientes = 0;

    return sade;
}

void liberaSade(miniSade* sade){
    int i;
    for(i = 0; i <= sade->qtdPacientes; i++){
        liberaPaciente(sade->pacientes[i]);
    }
    free(sade->pacientes);
    free(sade);

}

//Cadastro
void cadastro(miniSade* sade){
    sade->pacientes[sade->qtdPacientes] = lePaciente();

    //garantindo que o paciente novo não tem o meso cartão do sus que um paciente anterior
    int i;
    for(i = sade->qtdPacientes - 1; i >= 0; i--){
        if(ehMesmoPaciente(sade->pacientes[sade->qtdPacientes], sade->pacientes[i])){
            printf("Não é possivel pois já existe um paciente cadastrado com o mesmo numero");
            exit(1);
        }
    }

    sade->qtdPacientes++;

    //realocando lista(vetor) de ponteiros de pacientes
    sade->pacientes = (tPaciente **) realloc(sade->pacientes, ( (sade->qtdPacientes + 1) * sizeof(tPaciente *) ));

}

//Consulta (atendimento)
void consulta(miniSade* sade, int num_log){
    int i;
    char cartaoSus[19];

    scanf("%19[^\n]", cartaoSus);
    scanf("%*c");

    for(i = 0; i < sade->qtdPacientes; i++){
        if(EhPacienteCerto(sade->pacientes[i], cartaoSus)){
            
        }
    }
}

//Busca
//Relatorio