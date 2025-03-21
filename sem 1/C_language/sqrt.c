#include <stdio.h>
//Newton-Raphson method (technique for finding the roots)
int main() {
    float num;
    printf("Enter a number: ");
    scanf("%f", &num);
    if (num < 0) {
        printf("Square root of a negative number is not defined in real numbers.\n");
    } else {
        float guess = num / 2.0; // ensures that the guess is not too far from the actual square root.
        float epsilon = 0.00001; // determines how close the square of the guess needs to be.
        while ((guess * guess - num) >= epsilon || (num - guess * guess) >= epsilon) {
            // (guess * guess - num) >= epsilon) ensures that the guess is refined until it is sufficiently close to the actual square root.
            // both condition checks both positive and negative differences ensuring the loop works correctly.
            guess = (guess + num / guess) / 2.0;
            // This formula is the core of the Newton-Raphson method.
            // It refines the guess by averaging the current guess and the result of dividing the input number by the current guess.
        }
        printf("Square root of %f is %f\n", num, guess);
    }
    return 0;
}