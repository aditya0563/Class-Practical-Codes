#include <stdio.h>
int circle();
int rectangle();
int square();
int main() {
    char choosed;
    printf("1. Circle---> C \t 2. Rectangle---> R \t 3. Square---> S \nEnter the desired shape: ");
    scanf(" %c", &choosed);
    if (choosed == 'C') {
        circle();
    }else if (choosed == 'R'){
        rectangle();
    }else if (choosed == 'S'){
        square();
    }else{
        printf("inputted charcter is incorrect");
    }
    return 0;
}
int circle() {
    float radius;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    printf("Perimeter of the circle is: %f\n", 2 * 3.14 * radius);
    printf("Area of the circle is: %f\n", 3.14 * radius * radius);
    return 0;
}
int square() {
    float side;
    printf("Enter the side of the square: ");
    scanf("%f",&side);
    printf("Perimeter of the square is: %f\n", 4*side);
    printf("Area of the square is: %f\n", side*side);
    return 0;
}
int rectangle() {
    float length,breadth;
    printf("Enter the length of the reactangle: ");
    scanf("%f",&length);
    printf("Enter the brradth of the reactangle: ");
    scanf("%f",&breadth);
    printf("Perimeter of the reactangle is: %f\n", 2*(length+breadth));
    printf("Area of the rectangle is: %f\n", length*breadth);
    return 0;
}