# 位运算<<>>

给我几个C语言位运算左移右移应用的例子

# Answer

当然可以！以下是几个 C 语言中位运算左移和右移的应用例子：

### 1. 左移运算符 `<<`

左移运算符将一个数的二进制位向左移动指定的位数，右侧用零填充。这相当于对该数乘以 2 的 n 次幂（n 是移动的位数）。

```c
#include <stdio.h>

int main() {
    int num = 5; // 二进制：0000 0101
    int result = num << 2; // 左移2位
    printf("左移结果: %d\n", result); // 结果是20 (二进制：0001 0100)
    return 0;
}
```

### 2. 右移运算符 `>>`

右移运算符则是将一个数的二进制位向右移动指定的位数。对于无符号数，左侧用零填充；对于有符号整数，如果是负数，左侧用 1 填充（算术右移），如果是非负数，左侧用 0 填充（逻辑右移）。

```c
#include <stdio.h>

int main() {
    int num = 20; // 二进制：0001 0100
    int result = num >> 2; // 右移2位
    printf("右移结果: %d\n", result); // 结果是5 (二进制：0000 0101)
    return 0;
}
```

### 3. 使用位运算交换两个数

通过位运算可以在不使用额外变量的情况下交换两个数的值。

```c
#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;

    // 交换a和b
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("a: %d, b: %d\n", a, b); // a: 20, b: 10
    return 0;
}
```

### 4. 统计二进制数中1的个数

可以通过循环右移来逐位检查一个整数的二进制表示中有多少个 1。

```c
#include <stdio.h>

int countOnes(int num) {
    int count = 0;
    while (num) {
        count += (num & 1); // 检查最低位
        num >>= 1; // 右移
    }
    return count;
}

int main() {
    int num = 29; // 二进制：11101
    printf("1的个数: %d\n", countOnes(num)); // 结果是4
    return 0;
}
```

这些例子展示了如何在 C 语言中使用位运算的左移和右移操作，及其实际应用。希望对你有帮助！