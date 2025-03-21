//Write a program to print the series (1 + 2 + 2^2 +...... + N^2)
#include <stdio.h>
#include <math.h>
int main() {
    int n;
    double sum = 0;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        sum += pow(i, i);
    }
    printf("Sum of the series 1 + 2 + 2^2 + ... + %d^2 is: %.2f\n", n, sum);
    return 0;
}