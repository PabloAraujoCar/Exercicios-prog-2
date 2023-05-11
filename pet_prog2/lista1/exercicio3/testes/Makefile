contas: geraosConta principalsConta

principalsConta:
	gcc usuario.o conta.o testeConta.o -o testeConta.exe

geraosConta:
	gcc -c usuario.c conta.c testeConta.c 

user: geraosUser principalsUser

principalsUser:
	gcc usuario.o testeUsuario.o -o testeUser.exe

geraosUser:
	gcc -c usuario.c testeUsuario.c

clean:
	rm -rf *.o *.exe