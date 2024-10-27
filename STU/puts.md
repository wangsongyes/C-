# Question

C语言中puts的用法

# Answer

在C语言中，`puts`是一个用于输出字符串的函数。它可以将一个字符串输出到标准输出（通常是控制台），并在输出的字符串末尾自动添加换行符。`puts`的函数原型如下：

```c
int puts(const char *str);
```

### 用法示例：

```c
#include <stdio.h>

int main() {
    puts("Hello, World!"); // 输出 "Hello, World!" 并换行
    return 0;
}
```

### 注意事项：
1. `puts`函数的参数是一个指向字符串的指针，字符串以空字符`\0`结束。
2. `puts`函数返回一个非负值表示成功，返回EOF表示错误。

### 与`printf`的区别：
- `puts`只能输出字符串，而`printf`可以格式化输出各种类型的数据。
- `puts`输出后会自动换行，而`printf`不会，除非手动添加换行符`\n`。

使用`puts`是一个简单且快速的方法来输出字符串，适用于不需要特别格式化的场合。