#include <stdio.h>
#include <stdlib.h>

int main() {
    // 分配内存并初始化为零，分配 5 个整数大小的内存块
    int *arr = (int *)calloc(5, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // 使用分配的内存
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);  // 应该全是零
    }
    
    // 释放内存
    free(arr);

    return 0;
}