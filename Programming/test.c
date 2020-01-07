#include <stdio.h>

int suma(int a, int b) {
    return a + b;
}

int main() {
    void *ptr = 0x400714;
    printf("Hello, world! %08x\n", *((char *)ptr));
    printf("La suma es: %d\n", suma(5, 2));
}