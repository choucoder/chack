#include <stdio.h>

int ordenar(int [], int, int(*)(int, int));
int esMayor(int, int);
int esMenor(int, int);
void print_a(int [], int);
int main();

int(*main_ptr)(void) = &main;

int main() {
    int A[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(A) / sizeof(int);
    int(*comp_ptr)(int, int);

    print_a(A, n);
    comp_ptr = &esMenor;
    ordenar(A, n, comp_ptr);
    print_a(A, n);
    printf("Main address start at 0x%08x\n", main_ptr);
    return 0;
}

void print_a(int A[], int N) {
    int i;
    for(i=0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int esMayor(int a, int b) {
    return a > b;
}

int esMenor(int a, int b) {
    return a < b;
}

int ordenar(int A[], int N, int(*func_ptr)(int a, int b)) {
    int i, j, aux;
    
    for(i=1; i < N; i++) {
        for(j=0; j <= i - 1; j++) {
            if(func_ptr(A[i], A[j])) {
                aux = A[i];
                A[i] = A[j];
                A[j] = aux;
            }
        }
    }
}
