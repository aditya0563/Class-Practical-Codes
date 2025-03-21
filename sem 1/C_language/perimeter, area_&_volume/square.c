#include <stdio.h>
int main() {
    float side;
    printf("Enter the side of the square: ");
    scanf("%f",&side);
    printf("Perimeter of the square is: %f\n", 4*side);
    printf("Area of the square is: %f\n", side*side);
    return 0;
}