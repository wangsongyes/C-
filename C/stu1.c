#include <stdio.h>
#include <math.h>

// 计算一元二次方程的根
int main() {
    float a, b, c;
    float discriminant, root1, root2, realPart, imaginaryPart;

    printf("请输入一元二次方程的系数a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    discriminant = b*b - 4*a*c;

    // 判别式大于0，有两个不同的实2,数根
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2*a);
        root2 = (-b - sqrt(discriminant)) / (2*a);
        printf("方程有两个不同的实数根: \n");
        printf("根1 = %.2f 和 根2 = %.2f\n", root1, root2);
    }
    // 判别式等于0，有两个相同的实数根
    else if (discriminant == 0) {
        root1 = root2 = -b / (2*a);
        printf("方程有两个相同的实数根: \n");
        printf("根1 = 根2 = %.2f\n", root1);
    }
    // 判别式小于0，有两个共轭复数根
    else {
        realPart = -b / (2*a);
        imaginaryPart = sqrt(-discriminant) / (2*a);
        printf("方程有两个共轭复数根: \n");
        printf("根1 = %.2f + %.2fi 和 根2 = %.2f - %.2fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }

    return 0;
}
