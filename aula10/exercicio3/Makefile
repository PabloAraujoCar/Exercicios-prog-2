all: geraos principals

principals:
	gcc pessoa.o main.o -o principal

geraos:
	gcc -c pessoa.c main.c

clean:
	clear
	rm -rf *.o principal