#include <stdio.h>
void swap(float *first, float *second);
int main() {
    float first, second;
    printf("Enter the first number: ");
    scanf("%f", &first);
    printf("Enter the second number: ");
    scanf("%f", &second);
    if (first == second) {
        printf("They are the same.\n");
    } else {
        swap(&first, &second);
    }
    return 0;
}
void swap(float *first, float *second) {
    float temp = *first;
    *first = *second;
    *second = temp;
    printf("The first swapped number is %f\nThe second swapped number is %f\n", *first, *second);
}