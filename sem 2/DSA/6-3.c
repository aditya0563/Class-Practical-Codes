#include <stdio.h>
#include <stdbool.h>

#define MAX 5 // Define the maximum size of the circular queue

// Queue structure
typedef struct {
    int front, rear;
    int arr[MAX];
} CircularQueue;

// Function to initialize the queue
void initQueue(CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(CircularQueue* queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
bool isFull(CircularQueue* queue) {
    return ((queue->rear + 1) % MAX == queue->front);
}

// Function to add an element to the queue (enqueue)
bool enqueue(CircularQueue* queue, int x) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return false;
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX;
        queue->arr[queue->rear] = x;
        printf("%d enqueued to queue\n", x);
        return true;
    }
}

// Function to remove an element from the queue (dequeue)
int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int x = queue->arr[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1; // Reset the queue
        } else {
            queue->front = (queue->front + 1) % MAX;
        }
        return x;
    }
}

// Function to get the front element of the queue
int getFront(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return queue->arr[queue->front];
}

// Function to traverse and print the queue
void traverse(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty\n");
        return;
    }
    int i = queue->front;
    while (true) {
        printf("%d ", queue->arr[i]);
        if (i == queue->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CircularQueue queue;
    initQueue(&queue);

    // Perform queue operations
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    traverse(&queue); // Display elements in queue

    printf("%d dequeued from queue\n", dequeue(&queue));
    traverse(&queue); // Display elements after dequeue

    enqueue(&queue, 60);
    traverse(&queue); // Display elements after enqueue

    printf("Front element is %d\n", getFront(&queue));
    printf("Queue is empty: %s\n", isEmpty(&queue) ? "Yes" : "No");

    return 0;
}
