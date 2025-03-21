#include <stdio.h>
int main() {
    float radius, area;
    const float PI = 3.14159;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    area = PI * radius * radius;
    printf("The area of the circle with radius %.2f is %.2f\n", radius, area);
    return 0;
}
