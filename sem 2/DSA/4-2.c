#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int newData) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = *head;

    // Update the previous pointer of the current head, if it exists
    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    // Update the head to point to the new node
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int newData) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // Traverse to the end of the list
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the new node at the end
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node with a given key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;

    // Search for the key in the list
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If the key was not found
    if (temp == NULL) {
        printf("Key not found!\n");
        return;
    }

    // If the node to be deleted is the head node
    if (*head == temp) {
        *head = temp->next;
    }

    // Update the next pointer of the previous node, if it exists
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Update the previous pointer of the next node, if it exists
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    // Free the memory for the node
    free(temp);
}

// Function to update a node with a given key
void updateNode(struct Node* head, int key, int newData) {
    struct Node* temp = head;

    // Search for the key in the list
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If the key was not found
    if (temp == NULL) {
        printf("Key not found!\n");
        return;
    }

    // Update the node's data
    temp->data = newData;
}

// Function to traverse the list forward and print its elements
void traverseListForward(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to traverse the list backward and print its elements
void traverseListBackward(struct Node* head) {
    struct Node* temp = head;

    // Traverse to the end of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Traverse backward and print the elements
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Traverse and print the list forward
    printf("List after insertion (forward): ");
    traverseListForward(head);

    // Update a node
    updateNode(head, 20, 25);
    printf("List after updating (forward): ");
    traverseListForward(head);

    // Delete a node
    deleteNode(&head, 10);
    printf("List after deletion (forward): ");
    traverseListForward(head);

    // Traverse and print the list backward
    printf("List (backward): ");
    traverseListBackward(head);

    return 0;
}
