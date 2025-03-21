#include <iostream>
using namespace std;

#define MAX 5 // Define the maximum size of the circular queue

class CircularQueue {
    int front, rear;
    int arr[MAX]; // Queue array

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Function to check if the queue is full
    bool isFull() {
        return ((rear + 1) % MAX == front);
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
            rear = (rear + 1) % MAX;
            arr[rear] = x;
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
            int x = arr[front];
            if (front == rear) {
                front = rear = -1; // Reset the queue
            } else {
                front = (front + 1) % MAX;
            }
            return x;
        }
    }

    // Function to get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[front];
    }

    // Function to traverse and print the queue
    void traverse() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue queue;

    // Perform queue operations
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.traverse(); // Display elements in queue

    cout << queue.dequeue() << " dequeued from queue" << endl;
    queue.traverse(); // Display elements after dequeue

    queue.enqueue(60);
    queue.traverse(); // Display elements after enqueue

    cout << "Front element is " << queue.getFront() << endl;
    cout << "Queue is empty: " << (queue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
