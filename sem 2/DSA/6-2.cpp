#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Queue class to implement queue operations using a linked list
class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == nullptr);
    }

    // Function to add an element to the queue (enqueue)
    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << x << " enqueued to queue" << endl;
    }

    // Function to remove an element from the queue (dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        Node* temp = front;
        int dequeued = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr; // Reset the queue
        }
        delete temp;
        return dequeued;
    }

    // Function to get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return front->data;
    }

    // Function to traverse and print the queue
    void traverse() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    // Perform queue operations
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.traverse(); // Display elements in queue

    cout << queue.dequeue() << " dequeued from queue" << endl;
    queue.traverse(); // Display elements after dequeue

    cout << "Front element is " << queue.getFront() << endl;
    cout << "Queue is empty: " << (queue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
