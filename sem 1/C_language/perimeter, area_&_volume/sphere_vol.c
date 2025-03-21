#include <stdio.h>
int main() {
    float radius;
    printf("Enter the radius of the sphere: ");
    scanf("%f", &radius);
    printf("Volume of the Sphere is: %f\n", (4*3.14*radius*radius*radius)/3);
    return 0;
}
