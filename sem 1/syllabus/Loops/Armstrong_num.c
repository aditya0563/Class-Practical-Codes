//Write a program to display Armstrong numbers within a range specified by the user.
#include <stdio.h>
#include <math.h>
int main() {
    int low, high;
    printf("Enter the lower limit: ");
    scanf("%d", &low);
    printf("Enter the upper limit: ");
    scanf("%d", &high);
    printf("Armstrong numbers between %d and %d are: ", low, high);
    for(int num = low; num <= high; num++) {
        int sum = 0, temp = num, digits = 0;
        while (temp != 0) {
            temp /= 10;
            digits++;
        }
        temp = num;
        while (temp != 0) {
            int digit = temp % 10;
            sum += pow(digit, digits);
            temp /= 10;
        }
        if (sum == num) {
            printf("%d ", num);
        }
    }
    printf("\n");
    return 0;
}