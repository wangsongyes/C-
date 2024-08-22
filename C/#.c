#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 5;

    // 分配初始内存
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "内存分配失败\n");
        return 1;
    }

    // 初始化数组
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // 打印初始数组内容
    printf("初始数组内容:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // 调整数组大小
    n = 10;
    arr = (int *)realloc(arr, n * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "内存重新分配失败\n");
        return 1;
    }

    // 初始化新分配的部分
    for (int i = 5; i < n; i++) {
        arr[i] = i + 1;
    }

    // 打印调整后的数组内容
    printf("调整后的数组内容:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // 释放内存
    free(arr);

    return 0;
}
