#include <stdio.h>
int main() {
    int a = 10, b = 20;
    int *ptrA = &a;
    int *ptrB = &b;
    if (ptrA == ptrB) {
        printf("Both pointers point to the same location.\n");
    } else if (ptrA > ptrB) {
        printf("Pointer A points to a higher memory location than Pointer B.\n");
    } else {
        printf("Pointer B points to a higher memory location than Pointer A.\n");
    }
    return 0;
}