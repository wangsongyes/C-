#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    //访问数组元素
    printf("arr[0] = %d\n", arr[0]);
    printf("arr[1] = %d\n", arr[1]);

    //修改数组元素
    arr[0] = 10;
    printf("Modified arr[0] = %d\n", arr[0]);

    return 0;
}