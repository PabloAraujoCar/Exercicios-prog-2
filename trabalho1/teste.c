#include <stdio.h>
#include "paciente.h"

int main(){
    tPaciente* pacientes[3];
    int i;
    pacientes[0] = alocaPaciente();
    pacientes[1] = alocaPaciente();
    pacientes[2] = alocaPaciente();
    lePaciente(pacientes[0]);
    lePaciente(pacientes[1]);
    lePaciente(pacientes[2]);
    for (i = 0; i < 3; i++){
        imprimePaciente(pacientes[i]);
        liberaPaciente(pacientes[i]);
    }


    return 0;
}