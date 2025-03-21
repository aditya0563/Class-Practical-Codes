//Write a program to check if a number entered by the user is positive, negative, or zero.
#include <stdio.h>
int main(){
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (number > 0) {
        printf("%d is a positive number.\n", number);
    } else if (number < 0) {
        printf("%d is a negative number.\n", number);
    } else {
        printf("The number is zero.\n");
    }
    return 0;
}