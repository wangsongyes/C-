#include <stdio.h>
#include <math.h>

void solveLinearEquationX(double a, double b, double c ) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("The roots are %lf and %lf\n", root1, root2);
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        printf("The root is %lf\n", root);
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("The roots are %lf+i%lf and %lf-i%lf\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }
}

int main() {
    double a, b, c;
    printf("Enter the coefficients a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    solveLinearEquationX(a, b, c);

    return 0;
}



