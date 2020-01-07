#include <stdio.h>

int main() {
    int i;

    int int_array[5] = {1, 2, 3, 4, 5};
    char char_array[5] = {'a', 'b', 'c', 'd', 'c'};

    char *char_pointer;
    int *int_pointer;

    char_pointer = (char *) int_array;
    int_pointer = (int *) char_array;

    for(i=0; i < 5; i++) {
        printf("[integer pointer] points to %08x, which contains the char '%c'\n",
            int_pointer, *int_pointer);
        //int_pointer += 1;
        int_pointer = (int *) ((char *) int_pointer + 1);
    }

    for(i=0; i < 5; i++) {
        printf("[char pointer] points to %08x, which contains the char %d\n",
            char_pointer, *char_pointer);
        char_pointer += 1;
        //char_pointer = (char *) ((int *) char_pointer + 1);
    }
}