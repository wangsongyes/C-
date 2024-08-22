#include <stdio.h>
#include <stdlib.h>

int main() {
    // 分配一个整数大小的内存块
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // 使用分配的内存，所以在这个地方咱们就不用再定义那个int了对吧！ 
    *ptr = 10;
    printf("Value: %d\n", *ptr);
    
    // 释放内存
    free(ptr);

    return 0;
}

