#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main(){
    time *t;
    t = time_construir();
    time_ler(t);
    time_mostrar(t);
    
    return 0;
}