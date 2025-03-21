#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *sourceFile, *destFile;
    char sourceFilename[100], destFilename[100];
    char ch;
    printf("Enter the source filename: ");
    scanf("%s", sourceFilename);
    sourceFile = fopen(sourceFilename, "r");
    if (sourceFile == NULL) {
        printf("Could not open file %s for reading.\n", sourceFilename);
        return 1;
    }
    printf("Enter the destination filename: ");
    scanf("%s", destFilename);
    destFile = fopen(destFilename, "w");
    if (destFile == NULL) {
        printf("Could not open file %s for writing.\n", destFilename);
        fclose(sourceFile);
        return 1;
    }
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }
    fclose(sourceFile);
    fclose(destFile);
    printf("Contents copied from %s to %s successfully.\n", sourceFilename, destFilename);
    return 0;
}