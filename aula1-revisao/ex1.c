#include <stdio.h>

int main()
{
	int numLinhas, num, lin, col;
	num = 1;
	scanf("%d", &numLinhas);

	for (lin = 1; lin <= numLinhas; lin++){
		for (col = 1; col <= lin; col++){
			printf("%d  ", num);
			num++;
		}
		printf("\n");
	}
	
	return 0;
}
