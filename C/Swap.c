#include <stdio.h>  // 包含标准输入输出库

// 交换两个整数变量的值
void swap(int *a, int *b) {
    int temp = *a;  // 将a指向的值存储到临时变量temp中
    *a = *b;        // 将b指向的值赋给a指向的变量
    *b = temp;      // 将temp的值赋给b指向的变量
}

int main() {
    int x = 5, y = 10;  // 定义两个整数变量x和y，并分别初始化为5和10
    
    printf("Before swap: x = %d, y = %d\n", x, y);  // 输出交换前的x和y的值
    
    swap(&x, &y);  // 调用swap函数，交换x和y的值
    
    printf("After swap: x = %d, y = %d\n", x, y);  // 输出交换后的x和y的值
    
    return 0;  // 返回0，表示程序正常结束
}
