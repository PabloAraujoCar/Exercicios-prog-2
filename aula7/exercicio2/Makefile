all: clean geraos principal

principal:
	gcc cpf.o data.o pessoa.o main.o -o principal

geraos:
	gcc -c cpf.c data.c pessoa.c main.c

clean:
	rm -rf *.o principal