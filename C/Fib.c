#include <stdio.h>
#include <windows.h> // 包含Windows.h头文件

int fibnacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibnacci(n - 1) + fibnacci(n - 2);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Fibonacci number at position %d is %d\n", n, fibnacci(n));
    
    Sleep(5000); // 让程序暂停5000毫秒（5秒）
    
    return 0;
}
