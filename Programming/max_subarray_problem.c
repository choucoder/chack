#include <stdio.h>

#define SIZE_ARR 9
void maxSubArraySum(int *, int);
int array_sum(int *, int, int);

int main() {
    int array[] = {-1, -2, -3, -4};
    int n = sizeof(array) / sizeof(array[0]);
    maxSubArraySum(array, n);
}

// T = O(n)
int array_sum(int *array, int li, int lj) {
    int i, suma=0;
    
    for(i=li; i <= lj; i++)
        suma += array[i];
    return suma;
}

// T = O(n**3)
void maxSubArraySum(int *array, int size) {
    int li = 0;
    int lj = size;
    int i, j, k, suma=0, max=-100000;

    for(i=0; i < size; i++) {
        for(j=i; j < size; j++){
            suma = array_sum(array, i, j);
            if(suma > max) {
                max = suma;
                li = i;
                lj = j;
            }
        }
    }
    printf("Suma maxima: %d\n", max);
    printf("li: %d, lj: %d\n", li, lj);
}