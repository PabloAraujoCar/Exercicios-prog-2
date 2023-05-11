all: geraos principals

principals:
	gcc usuario.o conta.o main.o -o principals.exe

geraos:
	gcc -c usuario.c conta.c main.c

clean:
	rm -rf *.o *.exe