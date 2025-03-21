#include <stdio.h>
int main() {
    float radius;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    printf("Perimeter of the circle is: %f\n", 2 * 3.14 * radius);
    printf("Area of the circle is: %f\n", 3.14 * radius * radius);
    return 0;
}
