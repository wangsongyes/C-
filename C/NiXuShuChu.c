#include <stdio.h>

int main() {
    int arr[5];
    int i;

    //输入数组元素
    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    //输出数组元素（反序）
    printf("Reversedarray:\n");
    for (i = 4; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}