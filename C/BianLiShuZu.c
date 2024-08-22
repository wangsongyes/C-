#include <stdio.h>

int main() {
    // 定义一个数组
    int array[] = {1, 2, 3, 4, 5};
    
    // 计算数组的长度
    int length = sizeof(array) / sizeof(array[0]);
    
    // 使用for循环遍历数组
    for (int i = 0; i < length; i++) {
        printf("%d\n", array[i]);
    }
    
    //使用while循环遍历数组
    int i = 0;
    while (i < length) {
        printf("%d\n", array[i]);
        i++;
    }
    
    return 0;
}
