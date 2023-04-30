#include <stdio.h>
void func1(float *p) {
    printf("%f\n", *p);
}
void func2(float *p) {
    func1(p);
}
int main() {
    float *p = 0;
    func1(p);
    return 0;
}
