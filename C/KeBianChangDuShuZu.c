#include <stdio.h>

int main() {
    int n;
    printf("请输入数组的长度：");
    scanf("%d", &n);

    int arr[n];

    //初始化数组
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }


    //打印数组元素
    printf("数组元素：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        printf("\n");
    }

    return 0;

}
