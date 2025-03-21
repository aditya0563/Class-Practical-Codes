#include <stdio.h>
int main() {
    float radius,height;
    printf("Enter the radius of the cone: ");
    scanf("%f", &radius);
    printf("Enter the height of the cone: ");
    scanf("%f", &height);
    printf("Volume of the cone is: %f\n", (3.14 * radius*radius*height)/3);
    return 0;
}
