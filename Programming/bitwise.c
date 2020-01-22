#include <stdio.h>

/*
i = 0
00000000
00000010
---------
00000000

i = 1
00000001
00000010
--------
00000000

i = 2
00000010
00000010
--------
00000010

i = 3
*/

int main() {
    int i, bit_a, bit_b;
    printf("bitwise OR operator |\n");

    for(i=0; i < 4; i++) {
        bit_a = (i & 2) / 2;
        bit_b = (i & 1);
        printf("%d | %d = %d\n", bit_a, bit_b, bit_a | bit_b);
    }
    printf("bitwise AND operator |\n");
    for(i=0; i < 4; i++) {
        bit_a = (i & 2) / 2;
        bit_b = (i & 1);
        printf("%d & %d = %d\n", bit_a, bit_b, bit_a & bit_b);
    }
}