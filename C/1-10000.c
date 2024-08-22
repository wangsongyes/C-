#include <stdio.h>

//计算1-10000之间，能被3整除的数字的和
void sumOfMultiplesOf3( ) {
    int sum = 0;
    int i = 1;
    while (i <= 10000) {
        if (i % 3 == 0) {
            sum += i;
        }
        i++;
    }
    printf("The sum of multiples of 3 is %d\n", sum);
}

int main( ) {
    sumOfMultiplesOf3( );
    return 0;
}