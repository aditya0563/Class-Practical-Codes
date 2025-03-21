#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BOOKS 100
#define TITLE_SIZE 100
#define AUTHOR_SIZE 100
typedef struct {
    int id;
    char title[TITLE_SIZE];
    char author[AUTHOR_SIZE];
} Book;
Book library[MAX_BOOKS];
int bookCount = 0;
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }
    Book newBook;
    newBook.id = bookCount + 1;
    printf("Enter title: ");
    getchar(); // To consume the newline character left by previous input
    fgets(newBook.title, TITLE_SIZE, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline character
    printf("Enter author: ");
    fgets(newBook.author, AUTHOR_SIZE, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove newline character
    library[bookCount] = newBook;
    bookCount++;
    printf("Book added successfully!\n");
}
void viewBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("Library Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
    }
}
void deleteBook() {
    if (bookCount == 0) {
        printf("No books to delete.\n");
        return;
    }
    int id;
    printf("Enter the ID of the book to delete: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            found = 1;
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];
            }
            bookCount--;
            printf("Book deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}
int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Delete Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}