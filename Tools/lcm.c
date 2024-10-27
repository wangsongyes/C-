#include <stdio.h>

// 计算最大公约数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 计算最小公倍数
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b; // 使用公式计算
}

int main() {
    int a = 15, b = 20;
    printf("最小公倍数是: %d\n", lcm(a, b));
    return 0;
}