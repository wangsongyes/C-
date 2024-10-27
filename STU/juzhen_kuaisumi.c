#include <stdio.h>

typedef struct {
    long long a, b, c, d;
} Matrix;

Matrix matrix_mult(Matrix m1, Matrix m2) {
    Matrix result;
    result.a = m1.a * m2.a + m1.b * m2.c;
    result.b = m1.a * m2.b + m1.b * m2.d;
    result.c = m1.c * m2.a + m1.d * m2.c;
    result.d = m1.c * m2.b + m1.d * m2.d;
    return result;
}

Matrix matrix_pow(Matrix base, int exp) {
    Matrix result = {1, 0, 0, 1}; // 单位矩阵
    while (exp) {
        if (exp % 2 == 1) {
            result = matrix_mult(result, base);
        }
        base = matrix_mult(base, base);
        exp /= 2;
    }
    return result;
}

long long fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    Matrix base = {1, 1, 1, 0};
    Matrix result = matrix_pow(base, n - 1);
    return result.a; // 返回 F(n) = result.a
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Fibonacci(%d) = %lld\n", n, fib(n));
    return 0;
}
