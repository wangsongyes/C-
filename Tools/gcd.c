#include <stdio.h>

//下面是迭代版本的gcd函数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
//下面是递归版本的gcd函数
/*
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
*/

int main() {
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int result = gcd(num1, num2);
    printf("%d\n", num1, num2, result);

    return 0;
}
