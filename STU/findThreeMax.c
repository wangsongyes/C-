#include <stdio.h>
#include <limits.h>

void findThreeMax(int arr[], int len) {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

    for (int i = 0; i < len; i++) {
        if (arr[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2) {
            max3 = max2;
            max2 = arr[i];
        } else if (arr[i] > max3) {
            max3 = arr[i];
        }
    }

    printf("第一大的数为：%d\n", max1);
    printf("第二大的数为：%d\n", max2);
    printf("第三大的数为：%d\n", max3);
}

int main() {
    int arr[] = {3, 6, 9, 2, 5, 8};
    int len = sizeof(arr) / sizeof(arr[0]);

    findThreeMax(arr, len);

    return 0;
}
