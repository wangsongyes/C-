# Question

C语言Switch语句

# Answer

在C语言中，`switch` 语句是一种控制语句，用于根据变量的值选择执行不同的代码块。它的基本结构如下：

```c
switch (expression) {
    case constant1:
        // 语句块1
        break; // 可选，跳出switch语句
    case constant2:
        // 语句块2
        break;
    // 可以有任意多个case
    default:
        // 默认语句块（可选）
}
```

### 主要组成部分：
1. **expression**：这是需要进行判断的表达式，通常是一个整型或字符型的变量。
2. **case**：每一个`case`标签后跟一个常量，表示比较expression的值是否与之相等。
3. **break**：这个语句用于退出`switch`块。如果没有`break`，程序会继续执行下一个`case`中的代码，直到遇到break或switch结束。
4. **default**：这是可选的，表示在没有匹配的`case`时执行的代码。

### 示例代码：
```c
#include <stdio.h>

int main() {
    int day = 3;
    
    switch (day) {
        case 1:
            printf("今天是星期一。\n");
            break;
        case 2:
            printf("今天是星期二。\n");
            break;
        case 3:
            printf("今天是星期三。\n");
            break;
        case 4:
            printf("今天是星期四。\n");
            break;
        case 5:
            printf("今天是星期五。\n");
            break;
        default:
            printf("输入的数字无效。\n");
    }
    
    return 0;
}
```

在上述示例中，程序根据`day`的值打印出相应的星期几。如果`day`的值是3，程序将输出“今天是星期三。”。如果输入的值不在1到5之间，则会输出“输入的数字无效。”。