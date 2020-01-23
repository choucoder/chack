#include <stdio.h>
#include <math.h>

#define SIZE_ARR 9
int maxSubArraySum(int *, int);
int maxSubArraySum_K(int *, int);
int array_sum(int *, int, int);

int main() {
    int array[] = {-1, -2, -3, -4};
    int n = sizeof(array) / sizeof(array[0]);
    printf("%d\n", maxSubArraySum_K(array, n));
}

// T = O(n)
int array_sum(int *array, int li, int lj) {
    int i, suma=0;
    
    for(i=li; i <= lj; i++)
        suma += array[i];
    return suma;
}

// T = O(n**3)
int maxSubArraySum(int *array, int size) {
    int li = 0;
    int lj = size;
    int i, j, k, suma=0, max=(pow(2, (int)sizeof(int)) - 1)*-1;

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
    return max;
}
// a) Si se conocieran las sumas maximas para cada j,
// la complejidad del problema quedaria reducida ya que
// no seria necesario calcular la suma para cada j y de alli
// calcular el maximo de esas sumas

/*
    b) ¿Como se relaciona el maximo de listados terminando en
    la posicion j y el maximo de listados terminando en la 
    posicion j + 1?
*/
// Complejidad T(n) = n + 3 = O(n) 
int maxSubArraySum_K(int *a, int size) {
    int max_hasta_aqui = (pow(2, (int)sizeof(int)) - 1)*-1;
    int max_terminando_aqui = 0;
    int i;

    for(i=0; i < size; i++) {
        max_terminando_aqui = max_terminando_aqui + a[i];
        if(max_hasta_aqui < max_terminando_aqui)
            max_hasta_aqui = max_terminando_aqui;
        if(max_terminando_aqui < 0)
            max_terminando_aqui = 0;
    }
    return max_hasta_aqui;
}

/*
Kadane's algorithm:

    Inicializar:
        max_hasta_aqui = 0
        max_terminando_aqui = 0

    Ciclo para cada elemento del arreglo
        (a) max_terminando_aqui = max_terminando_aqui + a[i]
        (b) si(max_terminando_aqui < 0)
            max_terminando_aqui = 0
        (c) si(max_hasta_aqui < max_terminando_aqui)
            max_hasta_aqui = max_terminando_aqui
    
    return max_hasta_aqui

*/