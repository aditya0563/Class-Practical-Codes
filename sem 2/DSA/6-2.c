#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure to manage front and rear pointers
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue* queue, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d enqueued to queue\n", x);
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    Node* temp = queue->front;
    int dequeued = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL; // Reset the queue
    }
    free(temp);
    return dequeued;
}

// Function to get the front element of the queue
int getFront(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return queue->front->data;
}

// Function to traverse and print the queue
void traverse(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty\n");
        return;
    }
    Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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
