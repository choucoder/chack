#include <stdio.h>
#include <stdlib.h>

int numero(void) {
    return 16;
}

int main() {
    int *int_ptr;

    int_ptr = (int *)malloc(4);
    *int_ptr = numero();

    printf("Hello world! %d\n", *int_ptr);
    return 0;
}