#include <stdio.h>

//利用位运算把一个16位的无符号数a的高低字节互换
unsigned short swap_bytes(unsigned short a) {
    return (a << 8) | (a >> 8);
}

//输入一个正整数a（用unsigned int), 一个整数X（2<=X<=16）, 输出a的X进制表示（不含前导零）
void print_in_X_base(unsigned int a, int X) {
    unsigned int mask = 0x0000FFFF; // 16位掩码
    unsigned int digit = 0; // 记录当前位数
    unsigned int temp = a; // 临时变量
    
    while (temp!= 0) {
        digit++;
        temp >>= X;
    }
    
    temp = a;
    for (int i = digit; i >= 1; i--) {
        unsigned int base = 1 << (X * (i - 1)); // 基数
        unsigned int digit_value = (temp & base) >> (X * (i - 1)); // 取出当前位数的值
        printf("%d", digit_value);
    }
    printf("\n");
}


int main() {
    unsigned short a;
    scanf("%hu", &a);
    
    unsigned short swapped = swap_bytes(a);
    printf("%hu\n", swapped);
    
    return 0;
}
