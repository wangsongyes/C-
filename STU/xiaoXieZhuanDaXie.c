#include <stdio.h>

int main() {
    int ch;
    while((ch=getchar())!=EOF) {
        if(ch>='a' && ch<='z') {
            printf("%c",ch-32);
        }
        else
            printf("%c",ch);
    }
    return 0;


    }