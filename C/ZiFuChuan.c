#include <stdio.h>
#include <string.h>

int main() {
    //声明并初始化一个字符数组
    char str1[] = "Hello, world!";
    //输出数组中的字符
    printf("str1: %s\n", str1);

    //也可以明确指定数组大小（可以剩余空间）
    char str2[20] = "Hello, world!";
    printf("str2: %s\n", str2);
    
    //可以只初始化部分元素
    char str3[10] = "Hello";
    printf("str3: %s\n", str3);



    //计算字符串长度
    char str4[] = "Hello,world!";
    int len = strlen(str4);
    printf("str1 length: %d\n", len);



    //复制字符串
    char str5[] = "Hello";
    char dest[20];

    strcpy(dest, str5);
    printf("str5: %s\n", str5);
    printf("dest: %s\n", dest);



    //拼接字符串
    char str6[20] = "Hello";
    char str7[] = "world";

    strcat(str6, str7);     //str6 = str6 + str7; str7不变
    printf("Concatenated string: %s\n", str6);
    printf("Concatenated string: %s\n", str7);
    return 0;
}
