#include <iostream>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
};

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

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* head1, Node* head2) {
    // Create a dummy node to serve as the head of the merged list
    Node dummy;
    Node* tail = &dummy;
    dummy.next = nullptr;

    // Merge the two lists
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // Append the remaining elements of the list that is not yet fully traversed
    if (head1 != nullptr) {
        tail->next = head1;
    } else {
        tail->next = head2;
    }

    return dummy.next;
}

// Function to traverse and print the list
void traverseList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    // Insert elements into the first list
    insertAtEnd(head1, 1);
    insertAtEnd(head1, 3);
    insertAtEnd(head1, 5);

    // Insert elements into the second list
    insertAtEnd(head2, 2);
    insertAtEnd(head2, 4);
    insertAtEnd(head2, 6);

    // Merge the two sorted lists
    Node* mergedHead = mergeSortedLists(head1, head2);

    // Traverse and print the merged list
    cout << "Merged list: ";
    traverseList(mergedHead);

    return 0;
}
