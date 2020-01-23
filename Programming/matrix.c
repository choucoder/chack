#include <stdio.h>
#include <math.h>
#include <string.h>

int kadane(int *, int);
int findMaxSum(int matrix[4][4], int, int);

int main() {
    int matrix[][4] = {{0, -2, -7, 0},
                    {9, 2, -6, 2},
                    {-4, 1, -4, 1},
                    {-1, 8, 0, -2}};
    printf("%d\n", findMaxSum(matrix, 4, 4));
    return 0;
}

int findMaxSum(int matrix[4][4], int numRows, int numCols){
    int maxSum = 0;

    for(int left=0; left < numCols; left++) {
        int temp[numRows];
        memset(temp, 0, numRows);

        for(int right = left; right < numCols; right++) {
            for(int i=0; i < numRows; i++)
                temp[i] += matrix[i][right];

            int sum = kadane(temp, numRows);

            if(sum > maxSum)
                maxSum = sum;
        }
    }
    return maxSum;
}

int kadane(int *a, int size) {
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