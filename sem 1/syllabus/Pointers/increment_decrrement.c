#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Pointer to the first element of the array
    printf("Initial pointer value: %d\n", *ptr);
    ptr++;
    printf("After incrementing, pointer value: %d\n", *ptr);
    ptr--;
    printf("After decrementing, pointer value: %d\n", *ptr);
    return 0;
}
