#include <stdio.h>
union Student {
    char name[50];
    int rollNumber;
    float marks;
};
int main() {
    union Student students[5];
    char names[5][50];
    int rollNumbers[5];
    float marks[5];
    int i, lowestIndex = 0;
    for (i = 0; i < 5; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", names[i]);
        printf("Roll Number: ");
        scanf("%d", &rollNumbers[i]);
        printf("Marks: ");
        scanf("%f", &marks[i]);
    }
    for (i = 1; i < 5; i++) {
        if (marks[i] < marks[lowestIndex]) {
            lowestIndex = i;
        }
    }
    printf("\nStudent with the lowest marks:\n");
    printf("Name: %s\n", names[lowestIndex]);
    printf("Roll Number: %d\n", rollNumbers[lowestIndex]);
    printf("Marks: %.2f\n", marks[lowestIndex]);
    return 0;
}