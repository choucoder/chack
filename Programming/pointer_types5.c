#include <stdio.h>

int main() {
    int i;
    char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
    int int_array[5] = {1, 2, 3, 4, 5};

    long long int hacky_nonpointer;
    printf("Sizeof unsigned int is: 0x%08x\n", sizeof(unsigned int));
    printf("Sizeof char is: 0x%08x\n", sizeof(char));
    printf("Sizeof long long int is: 0x%08x\n", sizeof(long long int));
    printf("Sizeof int is: 0x%08x\n", sizeof(int));

    hacky_nonpointer = (long long int) char_array;

    for(i=0; i < 5; i++) {
        printf("[hacky_nonpointer] points to 0x%08x, which contains the char '%c'\n",
            hacky_nonpointer, *((char *) hacky_nonpointer));
        hacky_nonpointer = hacky_nonpointer + sizeof(char);
        //hacky_nonpointer = (unsigned int *)((char *)hacky_nonpointer + 1);
    }

    hacky_nonpointer = (long int) int_array;

    for(i=0; i < 5; i++) {
        printf("[hacky_nonpointer] points to 0x%08x, which contains the integer %d\n",
            hacky_nonpointer, *((int *) hacky_nonpointer));
        hacky_nonpointer = hacky_nonpointer + sizeof(int);
    }
}