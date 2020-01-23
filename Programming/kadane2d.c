#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define ROW 4
#define COL 5

int kadane(int *, int *, int *, int);
int array_sum(int *, int, int);

int main() {
    int M[][COL] = {    {1, 2, -1, -4, -20},
                        {-8, -3, 4, 2, 1},
                        {3, 8, 10, 1, 3},
                        {-4, -1, 1, 7, -6}};
    findMaxSum(M);
    bruteforce(M);
    return 0;
}

int array_sum(int *array, int li, int lj) {
    int i, suma=0;
    
    for(i=li; i <= lj; i++)
        suma += array[i];
    return suma;
}

int kadane(int *array, int *start, int *final,  int size) {
    int i, j, suma=0, max=(pow(2, (int)sizeof(int)) - 1)*-1;

    for(i=0; i < size; i++) {
        for(j=i; j < size; j++){
            suma = array_sum(array, i, j);
            if(suma > max) {
                max = suma;
                *start = i;
                *final = j;
            }
        }
    }
    return max;
}

void bruteforce(int M[][COL])
{
    int left, right, top, bottom;
    int suma, maxSuma = INT_MIN;
    int i, j, k, l, r;

    for(l=0; l < COL; l++)
    {
        for(r=l; r < COL; r++)
        {
            for(i=0; i < ROW; i++)
            {
                suma = 0;
                for(j=i; j < ROW; j++)
                {
                    for(k=l; k < r; k++)
                        suma += M[j][k];
                    if(maxSuma < suma)
                    {
                        maxSuma = suma;
                        left = l;
                        right = r - 1;
                        top = i;
                        bottom = j;
                    }
                }
            }
        }
    }
    printf("(top, left) (%d, %d)\n", top, left);
    printf("(Bottom, Right) (%d, %d)\n", bottom, right);
    printf("Max Suma: %d\n", maxSuma);
}

void findMaxSum(int M[][COL]) {
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
    int left, right, i;
    int temp[ROW], sum, start, finish;

    for(left=0; left < COL; left++) {
        memset(temp, 0, sizeof(temp));

        for(right=left; right < COL; ++right) {
            for(i=0; i < ROW; i++)
                temp[i] += M[i][right];
            sum = kadane(temp, &start, &finish, ROW);

            if(sum > maxSum)
            {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }
    printf("(top, left) (%d, %d)\n", finalTop, finalLeft);
    printf("(Bottom, Right) (%d, %d)\n", finalBottom, finalRight);
    printf("Max sum is: %d\n", maxSum);

}