#include <stdio.h>
int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) return 0;
    }
    return 1;
}
void printPrimes(int n) {
    int count = 0, num = 2;
    while (count < n) {
        if (isPrime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of prime numbers to print: ");
    scanf("%d", &n);
    printf("First %d prime numbers are: ", n);
    printPrimes(n);
    return 0;
}