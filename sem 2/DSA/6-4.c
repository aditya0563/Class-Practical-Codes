#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent a task
typedef struct {
    int id;      // Task ID
    int duration; // Task duration
} Task;

// Function to swap two tasks
void swap(Task* a, Task* b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain min-heap property
void heapify(Task arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].duration < arr[smallest].duration) {
        smallest = left;
    }
    if (right < n && arr[right].duration < arr[smallest].duration) {
        smallest = right;
    }
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Function to build the heap
void buildHeap(Task arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to remove the top task (execute)
void executeTasks(Task arr[], int* n) {
    while (*n > 0) {
        printf("Executing task ID: %d with duration: %d units\n", arr[0].id, arr[0].duration);
        swap(&arr[0], &arr[*n - 1]);
        (*n)--;
        heapify(arr, *n, 0);
    }
}

int main() {
    Task tasks[] = {{1, 5}, {2, 2}, {3, 8}, {4, 3}};
    int n = sizeof(tasks) / sizeof(tasks[0]);

    buildHeap(tasks, n);
    
    printf("Task Scheduler Simulation:\n");
    executeTasks(tasks, &n);

    return 0;
}
