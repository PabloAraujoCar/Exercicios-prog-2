#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

int main(){

    tUsuario *user;
    user = retornaPonteiroUsuario();
    leUsuario(user);
    imprimeUsuaraio(user);

    return 0 ;
}