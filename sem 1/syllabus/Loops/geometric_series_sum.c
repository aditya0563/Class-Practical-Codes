//Write a program to find the sum of geometric series using loops
#include <stdio.h>
#include <math.h>
int main() {
    int n;
    float a, r, sum = 0;
    printf("Enter the first term (a): ");
    scanf("%f", &a);
    printf("Enter the common ratio (r): ");
    scanf("%f", &r);
    printf("Enter the number of terms (n): ");
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        sum += a * pow(r, i);
    }
    printf("Sum of the geometric series: %.2f\n", sum);
    return 0;
}