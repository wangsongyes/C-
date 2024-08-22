#include <stdio.h>

// 函数原型声明
double solveLinearEquationX(double a1, double b1, double c1, double a2, double b2, double c2);
double solveLinearEquationY(double a1, double b1, double c1, double a2, double b2, double c2);

int main() {
    double a1, b1, c1; // 方程1的系数
    double a2, b2, c2; // 方程2的系数
    double x, y; // 存储方程组的解

    // 输入方程1的系数
    printf("Enter coefficients of equation 1 (a1, b1, c1): ");
    scanf("%lf %lf %lf", &a1, &b1, &c1);

    // 输入方程2的系数
    printf("Enter coefficients of equation 2 (a2, b2, c2): ");
    scanf("%lf %lf %lf", &a2, &b2, &c2);

    // 调用函数求解方程组
    x = solveLinearEquationX(a1, b1, c1, a2, b2, c2);
    y = solveLinearEquationY(a1, b1, c1, a2, b2, c2);

    // 输出结果
    printf("\nSolution:\n");
    printf("x = %.2f\n", x);
    printf("y = %.2f\n", y);

    return 0;
}

// 计算二元一次方程组 x 解的函数定义
double solveLinearEquationX(double a1, double b1, double c1, double a2, double b2, double c2) {
    // 计算主元 determinant D
    double D = a1 * b2 - a2 * b1;

    // 如果 D = 0，则方程组无唯一解
    if (D == 0) {
        printf("Error: The equations have no unique solution.\n");
        return 0.0; // 返回一个无效的解
    }

    // 计算 Dx 和 Dy
    double Dx = c1 * b2 - c2 * b1;

    // 计算解 x
    double x = Dx / D;

    return x;
}

// 计算二元一次方程组 y 解的函数定义
double solveLinearEquationY(double a1, double b1, double c1, double a2, double b2, double c2) {
    // 计算主元 determinant D
    double D = a1 * b2 - a2 * b1;

    // 如果 D = 0，则方程组无唯一解
    if (D == 0) {
        printf("Error: The equations have no unique solution.\n");
        return 0.0; // 返回一个无效的解
    }

    // 计算 Dy
    double Dy = a1 * c2 - a2 * c1;

    // 计算解 y
    double y = Dy / D;

    return y;
}