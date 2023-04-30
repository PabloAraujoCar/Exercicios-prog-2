#include <stdio.h>
#include <stdlib.h>

int main() {

    int *v = (int*) malloc(10 * sizeof(int));
    v[0] = 10;
    printf("v[0] = %d\n", v[0]);

    //free(v);

    return 0;
}
