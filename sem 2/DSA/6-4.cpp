#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Structure to represent a task
struct Task {
    int id;      // Task ID
    int duration; // Task duration

    // Constructor
    Task(int i, int d) : id(i), duration(d) {}
};

// Comparator to order tasks by their duration (shortest duration first)
struct TaskComparator {
    bool operator()(const Task& t1, const Task& t2) {
        return t1.duration > t2.duration;
    }
};

// Function to simulate the task scheduler
void simulateTaskScheduler(priority_queue<Task, vector<Task>, TaskComparator>& pq) {
    while (!pq.empty()) {
        Task currentTask = pq.top();
        pq.pop();
        cout << "Executing task ID: " << currentTask.id << " with duration: " << currentTask.duration << " units" << endl;
    }
}

int main() {
    priority_queue<Task, vector<Task>, TaskComparator> pq;

    // Insert tasks into the priority queue
    pq.push(Task(1, 5));
    pq.push(Task(2, 2));
    pq.push(Task(3, 8));
    pq.push(Task(4, 3));

    // Simulate the task scheduler
    cout << "Task Scheduler Simulation:" << endl;
    simulateTaskScheduler(pq);

    return 0;
}
