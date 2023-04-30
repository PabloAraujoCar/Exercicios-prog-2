#include <stdio.h>
int main() {
    int x = 3;
    float *p = 0;

    printf("Imprimindo valores:\n");
    printf("%d\n", x);
    printf("%p\n", &x);
    printf("%p\n", p);
    //printf("%f\n", *p);

    return 0;
}
