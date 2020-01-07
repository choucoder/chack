#include <stdio.h>
#include <string.h>

void strcpy_a(char *dest, char *orig) {
    strcpy(dest, orig);
}

int main() {
    char str_a[20];

    strcpy_a(str_a, "Hello, world!\n");
    printf("%s", str_a);
}