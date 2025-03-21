#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main() {
    FILE *file;
    char filename[100];
    char ch;
    int words = 0, spaces = 0;
    int inWord = 0;
    printf("Enter the filename to open: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s for reading.\n", filename);
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            spaces++;
            if (inWord) {
                words++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }
    if (inWord) {
        words++;
    }
    fclose(file);
    printf("Total words: %d\n", words);
    printf("Total spaces: %d\n", spaces);
    return 0;
}