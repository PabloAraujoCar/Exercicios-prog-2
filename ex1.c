#include <stdio.h>
#include <math.h>

/*esse programa vê se dois circulos em um mesmo plano estão se tocando ou não
Pablo Araujo
23/03/2023 */

float calculaDistancia (int x1, int y1, int x2, int y2);


int main()
{
   int x1, y1, x2, y2, r1, r2;
   float dist, somaRaios;


   printf("Digite x1, y1, r1, x2, y2, r2 \n");
   scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);


   somaRaios = r1 + r2;
   dist = calculaDistancia(x1, y1, x2, y2);
   if (dist <= somaRaios){
       printf("Acertou \n");
   }else{
       printf("Errou \n");
   }


   return 0;
}


float calculaDistancia (int x1, int y1, int x2, int y2){
   int dx, dy;
   float raiz;
   dx = x2 - x1;
   dy = y2 - y1;
   raiz = sqrt( dx*dx + dy*dy );
   return raiz;
}

