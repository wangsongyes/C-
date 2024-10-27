//输入一段文字，即若干字符（字符数个数区间为1~10000），把输入文字的每个单词的首字母大写，其他字符不变。

#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[10001];
    int i, j, len;

    // 读入字符串
    printf("Please input a string (1~10000 characters): ");
    fgets(str, 10001, stdin);

    // 计算字符串长度
    len = strlen(str);

    // 遍历字符串
    for (i = 0; i < len; i++)
    {
        // 若当前字符为字母，则将其首字母大写，其余字母小写
        if (isalpha(str[i]))
        {
            if (i == 0 || !isalpha(str[i-1]))
            {
                str[i] = toupper(str[i]);
            }
        }
    }

    // 输出结果
    printf("%s", str);

    return 0;
}