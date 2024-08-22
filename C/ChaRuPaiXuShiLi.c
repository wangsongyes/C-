#include <stdio.h>

// 函数定义：找出整数数组中的最小值和最大值
// void minmax(int a[], int len, int *max, int *min) {
//     int i;
//     *min = a[0]; // 初始化最小值为数组第一个元素
//     *max = a[0]; // 初始化最大值为数组第一个元素
    
//     // 遍历数组，更新最小值和最大值
//     for (i = 0; i < len; i++) {
//         if (a[i] < *min) { // 如果当前元素比当前最小值还小
//             *min = a[i];  // 更新最小值
//         }
//         if (a[i] > *max) { // 如果当前元素比当前最大值还大
//             *max = a[i];  // 更新最大值
//         }
//     }
// }

//改为插入排序算法
void insertionsort(int a[], int len) {
    for (int i = 1; i < len; i++) {
        int key = a[i]; // 待插入元素
        int j = i - 1; // 从i-1开始比较
        while (j >= 0 && a[j] > key) { // 找到插入位置
            a[j + 1] = a[j]; // 元素后移
            j--; // 继续比较
        }
        a[j + 1] = key; // 插入元素
    }
}
int main(void) {
    int a[5]; 
    printf("请依次输入数组元素(5个整数)：");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]); // 输入数组元素
    }
    printf("请输入，你想要输出第几小或第几大的元素（一个整数）：");
    int n;
    scanf("%d", &n); // 输入需要输出的元素序号
    
    insertionsort(a, sizeof(a) / sizeof(a[0]));
    
    // 打印计算得到的最小值和最大值
    printf("第%d小的元素为：%d\n，第%d大的元素为：%d\n", n, a[n-1], n, a[5-n] );
    
    return 0; // 返回主函数结束标志，表示程序正常执行结束
}