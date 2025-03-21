#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node with a given key
void deleteNode(Node*& head, int key) {
    Node* temp = head;

    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Key not found!" << endl;
        return;
    }

    if (head == temp) {
        head = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

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

// Function to traverse the list forward and print its elements
void traverseListForward(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to traverse the list backward and print its elements
void traverseListBackward(Node* head) {
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements
    insertAtBeginning(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    // Traverse and print the list forward
    cout << "List after insertion (forward): ";
    traverseListForward(head);

    // Update a node
    updateNode(head, 20, 25);
    cout << "List after updating (forward): ";
    traverseListForward(head);

    // Delete a node
    deleteNode(head, 10);
    cout << "List after deletion (forward): ";
    traverseListForward(head);

    // Traverse and print the list backward
    cout << "List (backward): ";
    traverseListBackward(head);

    return 0;
}
