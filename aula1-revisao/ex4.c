#include <stdio.h>

/*Programa que lê um nûmero em decimal e converte para octal
Pablo Araujo
25/03/2023*/

int main(){
	int numDec, numOct = 0, aux, i ;
	printf ("Digite um número natural em Decimal para ser convertido para Octal \n");
	scanf("%d", &numDec);
	aux = numDec;

	for(i = 1; numDec > 0; i = i * 10){
		numOct = numOct + (numDec % 8) * i;
		numDec = numDec / 8; 
	}
	numDec = aux;
	printf("O numero decimal %d é igual ao número %d em Octal \n", numDec, numOct);

	return 0;
}