#include <stdio.h>
int main() {
    float length,breadth;
    printf("Enter the length of the reactangle: ");
    scanf("%f",&length);
    printf("Enter the brradth of the reactangle: ");
    scanf("%f",&breadth);
    printf("Perimeter of the reactangle is: %f\n", 2*(length+breadth));
    printf("Area of the rectangle is: %f\n", length*breadth);
    return 0;
}