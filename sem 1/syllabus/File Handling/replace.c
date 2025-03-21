#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1000
int main() {
    FILE *fPtr, *fTemp;
    char path[100];
    char buffer[BUFFER_SIZE];
    char newline[BUFFER_SIZE];
    int line, count = 0;
    printf("Enter path of source file: ");
    scanf("%s", path);
    printf("Enter line number to replace: ");
    scanf("%d", &line);
    getchar();
    printf("Enter new text to replace the line: ");
    fgets(newline, BUFFER_SIZE, stdin);
    fPtr = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w");
    if (fPtr == NULL || fTemp == NULL) {
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_FAILURE);
    }
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL) {
        count++;
        if (count == line) {
            fputs(newline, fTemp);
        } else {
            fputs(buffer, fTemp);
        }
    }
    fclose(fPtr);
    fclose(fTemp);
    remove(path);
    rename("replace.tmp", path);
    printf("Successfully replaced line %d with '%s'.\n", line, newline);
    return 0;
}
