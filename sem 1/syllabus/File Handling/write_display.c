#include <stdio.h>
int main() {
    FILE *file;
    char filename[100], data[1000];
    printf("Enter the filename to write to: ");
    scanf("%s", filename);
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not open file %s for writing.\n", filename);
        return 1;
    }
    printf("Enter data to write to the file: ");
    getchar();
    fgets(data, sizeof(data), stdin);
    fputs(data, file);
    fclose(file);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s for reading.\n", filename);
        return 1;
    }
    printf("Contents of the file %s:\n", filename);
    while (fgets(data, sizeof(data), file) != NULL) {
        printf("%s", data);
    }
    fclose(file);
    return 0;
}