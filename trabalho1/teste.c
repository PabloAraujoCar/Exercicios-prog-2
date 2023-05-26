#include <stdio.h>
#include "paciente.h"

int main(){
    tPaciente *p;
    p = alocaPaciente();
    lePaciente(p);
    imprimePaciente(p);


    return 0;
}