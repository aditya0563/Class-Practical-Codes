#include <stdio.h>
union Student {
    char name[50];
    int rollNumber;
    float marks;
};
int main() {
    union Student student;
    printf("Enter name: ");
    gets(student.name);
    printf("Name: %s\n", student.name);
    printf("Enter roll number: ");
    scanf("%d", &student.rollNumber);
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Enter marks: ");
    scanf("%f", &student.marks);
    printf("Marks: %.2f\n", student.marks);
    return 0;
}