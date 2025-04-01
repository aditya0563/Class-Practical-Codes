#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int newData) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode; // Update the head to point to the new node
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int newData) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse to the end of the list
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // Link the new node to the end of the list
    temp->next = newNode;
}

// Function to delete a node with a given key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Update the head
        free(temp); // Free memory of the old head
        return;
    }

    // Search for the key in the list
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not found in the list
    if (temp == NULL) {
        printf("Key not found!\n");
        return;
    }

    // Unlink the node from the list and free its memory
    prev->next = temp->next;
    free(temp);
}

// Function to update a node with a given key
void updateNode(struct Node* head, int key, int newData) {
    struct Node* temp = head;

    // Search for the key in the list
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If the key was not found in the list
    if (temp == NULL) {
        printf("Key not found!\n");
        return;
    }

    // Update the node's data
    temp->data = newData;
}

// Function to traverse the list and print its elements
void traverseList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Traverse and print the list
    printf("List after insertion: ");
    traverseList(head);

    // Update a node
    updateNode(head, 20, 25);
    printf("List after updating: ");
    traverseList(head);

    // Delete a node
    deleteNode(&head, 10);
    printf("List after deletion: ");
    traverseList(head);

    return 0;
}
