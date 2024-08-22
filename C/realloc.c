#include <stdio.h>
#include <stdlib.h>

/*
调整先前分配的内存块的大小。可以增加或减少内存块的大小。
如果需要增加大小，realloc 可能会移动内存块到新的位置。
*/

int main() {
    // 初始分配内存
    int *arr = (int *)malloc(3 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // 初始化内存
    for (int i = 0; i < 3; i++) {
        arr[i] = i + 1;
    }
    
    // 调整内存块大小
    arr = (int *)realloc(arr, 5 * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }
    
    // 新分配的内存块的内容未初始化
    for (int i = 3; i < 5; i++) {
        arr[i] = i + 1;
    }
    
    // 使用和打印内存
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    // 释放内存
    free(arr);

    return 0;
}

