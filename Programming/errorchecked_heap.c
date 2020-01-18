#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *errorchecked_heap(unsigned int);

int main(int argc, char *argv[]) {
    char *char_ptr;
    int *int_ptr;
    int mem_size;

    if (argc < 2)
        mem_size =  50;
    else
        mem_size = atoi(argv[1]);
    
    printf("\t[+] allocating %d bytes of memory on the heap for char_ptr\n", mem_size);
    char_ptr = (char *) errorchecked_heap(mem_size);

    strcpy(char_ptr, "This is memory located on the heap.");
    printf("char_ptr (%p) --> '%s'\n", char_ptr, char_ptr);
    printf("\t[+] allocating 12 bytes of memory on the heap for int_ptr\n");
    int_ptr = (int *) errorchecked_heap(12);

    *int_ptr = 31337;
    printf("int_ptr (%p) --> %d\n", int_ptr, *int_ptr);

    printf("\t[-] freeing char_ptr's heap memory...\n");
    free(char_ptr);

    printf("\t[+] allocating aonther 15 bytes for char_ptr\n");
    char_ptr = (char *) errorchecked_heap(15);

    strcpy(char_ptr, "new memory");
    printf("\t[-] freeing int_ptr's heap memory...\n");
    free(int_ptr);
    printf("\t[-] freeing char_PTR's heap memory...\n");
    free(char_ptr);
}

void *errorchecked_heap(unsigned int size) {
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error could not allocate memory heap.\n");
        exit(-1);
    }
    return ptr;
}