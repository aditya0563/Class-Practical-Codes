#include <stdio.h>
#include <stdbool.h>//It provides a way to work with boolean data types, which represent true and false values. 
bool isPrime(int num){
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Prime numbers before %d are:\n", n);
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}