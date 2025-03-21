//Write a program to find the factorial of a given number using loops
#include <stdio.h>
int main() {
    int n;
    unsigned long long factorial = 1;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
    } else {
        for(int i = 1; i <= n; ++i) {
            factorial *= i;
        }
        printf("Factorial of %d = %llu\n", n, factorial);
    }
    return 0;
}