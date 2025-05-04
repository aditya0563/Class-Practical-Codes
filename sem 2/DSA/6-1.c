#include <stdio.h>
#include <stdbool.h>

#define MAX 1000 // Define maximum size of the queue

// Queue structure
typedef struct {
    int front, rear;
    int arr[MAX];
} Queue;

// Function to initialize the queue
void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

// Function to check if the queue is full
bool isFull(Queue* queue) {
    return (queue->rear == MAX - 1);
}

// Function to add an element to the queue (enqueue)
bool enqueue(Queue* queue, int x) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return false;
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->arr[++queue->rear] = x;
        printf("%d enqueued to queue\n", x);
        return true;
    }
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int x = queue->arr[queue->front++];
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1; // Reset the queue
        }
        return x;
    }
}

// Function to get the front element of the queue
int getFront(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty\n");
        return -1;
    } else {
        return queue->arr[queue->front];
    }
}

// Function to traverse and print the queue
void traverse(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty\n");
        return;
    } else {
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue queue;
    initQueue(&queue);

    // Perform queue operations
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    traverse(&queue); // Display elements in queue

    printf("%d dequeued from queue\n", dequeue(&queue));
    traverse(&queue); // Display elements after dequeue

    printf("Front element is %d\n", getFront(&queue));
    printf("Queue is empty: %s\n", isEmpty(&queue) ? "Yes" : "No");

    return 0;
}
