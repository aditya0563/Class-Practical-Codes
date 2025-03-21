#include <stdio.h>
#include <math.h>
int main() {
    double a, b, c, discriminant, root1, root2, realPart, imagPart;
    printf("Enter coefficients a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    // Calculating the discriminant
    discriminant = b * b - 4 * a * c;
    // Checking the nature of the roots
    if (discriminant > 0) {
        // Two distinct and real roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("root1 = %.2lf and root2 = %.2lf\n", root1, root2);
    } else if (discriminant == 0) {
        // Two equal and real roots
        root1 = root2 = -b / (2 * a);
        printf("root1 = root2 = %.2lf\n", root1);
    } else {
        // Two distinct complex roots
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);
        printf("root1 = %.2lf + %.2lfi and root2 = %.2lf - %.2lfi\n", realPart, imagPart, realPart, imagPart);
    }
    return 0;
}