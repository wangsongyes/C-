#include <stdio.h>

int main() {
    char buffer[100];

    printf("请输入一行文本：");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        printf("您输入的内容是：%s", buffer);
    } else {
        printf("读取失败！\n");
    }

    return 0;
}
