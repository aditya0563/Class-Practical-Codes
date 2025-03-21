//Write a program to display characters from A to Z using a loop.
#include <stdio.h>
int main() {
    char ch;
    for(ch = 'A'; ch <= 'Z'; ++ch) {
        printf("%c ", ch);
    }
    return 0;
}