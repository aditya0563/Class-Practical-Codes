#include <stdio.h>
int main() {
    char str[100];
    int count = 0, i = 0;
    printf("Enter a sentence: ");
    gets(str);
    while (str[i] != '\0') {
        if (str[i] == ' ' && str[i+1] != ' ' && str[i+1] != '\0') {
            count++;
        }
        i++;
    }
    count++;
    printf("Number of words in the sentence: %d\n", count);
    return 0;
}