#ifndef _USUARIO_H
#define _USUARIO_H

typedef struct tUsuario tUsuario;


tUsuario* retornaPonteiroUsuario();
void leUsuario(tUsuario *user);
void imprimeUsuario(tUsuario *user);
void imprimeSoNomeUser(tUsuario *user);
void liberaUsuario(tUsuario *user);
#endif