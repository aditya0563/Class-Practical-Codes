#include <stdio.h>
int main() {
    int intType;
    float floatType;
    char charType;
    printf("Size of int: %zu bytes\n", sizeof(intType));
    printf("Size of float: %zu bytes\n", sizeof(floatType));
    printf("Size of char: %zu byte\n", sizeof(charType));
    return 0;
}
