#include <stdio.h>

/*programa que lê lista de numeros naturais (identidficadores) e diz quais não se repetem
Pablo Araujo
24/03/2023*/

int main(){
	int lista[100]; 
	int comprar[100];
	int numIdent, i, j, aux, controle, num = 0;

	printf("Digite a quantidade de livros da lista \n");
	scanf("%d", &numIdent);

	//separando os numeros repetidos em um vetor comprar.
	printf ("Digite a lista de livros \n");
	for(i = 0; i < numIdent; i++){
		scanf("%d", &lista[i]);
	}

	for(i = 0; i < numIdent; i++){
		controle = 0;

		for (j = 0; j < numIdent; j++){
			if (i != j && lista[i] == lista[j]){
				controle++;
				break;
			}
		}

		if (controle == 0){
				comprar[num] = lista[i];
				num++;
		}
	}
	//ordenando os numeros do vetor comprar
	for (i = 0; i < num; i++){
		for(j = i + 1; j < num; j++){
			if (comprar[j] < comprar[i]){
				aux = comprar[i];
				comprar[i] = comprar[j];
				comprar[j] = aux;
			}
		}
	}

	//imprimindo lista de livros a se comprar
	for (i = 0; i < num; i++){
		printf("%d ", comprar[i]);
	}
	printf("\n");

	return 0;
}