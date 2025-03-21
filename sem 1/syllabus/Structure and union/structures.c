#include <stdio.h>
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};
int main() {
    struct Student students[5];
    int i, highestIndex = 0;
    for (i = 0; i < 5; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
    for (i = 1; i < 5; i++) {
        if (students[i].marks > students[highestIndex].marks) {
            highestIndex = i;
        }
    }
    printf("\nStudent with the highest marks:\n");
    printf("Name: %s\n", students[highestIndex].name);
    printf("Roll Number: %d\n", students[highestIndex].rollNumber);
    printf("Marks: %.2f\n", students[highestIndex].marks);
    return 0;
}