#include <stdio.h>

//输入一个年份，判断这一年是否为闰年
void checkLeapYear() {
    int year;
    printf("Enter a year：");
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100!= 0) || (year % 400 == 0)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }
}

int main() {
    checkLeapYear();
    return 0;
}