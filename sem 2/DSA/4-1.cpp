#include <iostream>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with a given key
void deleteNode(Node*& head, int key) {
    Node* temp = head;
    Node* prev = nullptr;

    // If head node itself holds the key
    if (temp != nullptr && temp->data == key) {
        head = temp->next;
        delete temp;
        return;
    }

    // Search for the key
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not found
    if (temp == nullptr) {
        cout << "Key not found!" << endl;
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    delete temp;
}

// Function to update a node with a given key
void updateNode(Node* head, int key, int newData) {
    Node* temp = head;

    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Key not found!" << endl;
        return;
    }

    temp->data = newData;
}

// Function to traverse the list and print its elements
void traverseList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements
    insertAtBeginning(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    // Traverse and print the list
    cout << "List after insertion: ";
    traverseList(head);

    // Update a node
    updateNode(head, 20, 25);
    cout << "List after updating: ";
    traverseList(head);

    // Delete a node
    deleteNode(head, 10);
    cout << "List after deletion: ";
    traverseList(head);

    return 0;
}
