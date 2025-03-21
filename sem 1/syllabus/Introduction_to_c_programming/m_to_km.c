#include <stdio.h>
int main() {
    float kilometers, meters;
    int choice;
    printf("Choose the conversion:\n");
    printf("1. Kilometers to Meters\n");
    printf("2. Meters to Kilometers\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    if (choice == 1) {
        // Kilometers to Meters
        printf("Enter distance in kilometers: ");
        scanf("%f", &kilometers);
        meters = kilometers * 1000;
        printf("%.2f kilometers = %.2f meters\n", kilometers, meters);
    } else if (choice == 2) {
        // Meters to Kilometers
        printf("Enter distance in meters: ");
        scanf("%f", &meters);
        kilometers = meters / 1000;
        printf("%.2f meters = %.2f kilometers\n", meters, kilometers);
    } else {
        printf("Invalid choice!\n");
    }
    return 0;
}
