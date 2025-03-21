//Write a program to convert decimal to binary using recursion.
#include <stdio.h>
void decimalToBinary(int n) {
    if (n == 0) {
        return;
    }
    decimalToBinary(n / 2);
    printf("%d", n % 2);
}
int main() {
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    printf("Binary representation of %d is: ", n);
    if (n == 0) {
        printf("0");
    } else {
        decimalToBinary(n);
    }
    printf("\n");
    return 0;
}