#include <stdio.h>
#include <math.h>
int main() {
    float principal, rate, time, simpleInterest, compoundInterest;
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the rate of interest: ");
    scanf("%f", &rate);
    printf("Enter the time period (in years): ");
    scanf("%f", &time);
    simpleInterest = (principal * rate * time) / 100;
    compoundInterest = principal * (pow((1 + rate / 100), time) - 1);
    printf("Simple Interest = %.2f\n", simpleInterest);
    printf("Compound Interest = %.2f\n", compoundInterest);
    return 0;
}