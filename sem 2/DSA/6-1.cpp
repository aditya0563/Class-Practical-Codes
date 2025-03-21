#include <iostream>
using namespace std;

#define MAX 1000 // Define maximum size of the queue

class Queue {
    int front, rear;
    int arr[MAX]; // Queue array

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear == MAX - 1);
    }

    // Function to add an element to the queue (enqueue)
    bool enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return false;
        } else {
            if (front == -1) {
                front = 0;
            }
            arr[++rear] = x;
            cout << x << " enqueued to queue" << endl;
            return true;
        }
    }

    // Function to remove an element from the queue (dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        } else {
            int x = arr[front++];
            if (front > rear) {
                front = rear = -1; // Reset the queue
            }
            return x;
        }
    }

    // Function to get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        } else {
            return arr[front];
        }
    }

    // Function to traverse and print the queue
    void traverse() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        } else {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
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
