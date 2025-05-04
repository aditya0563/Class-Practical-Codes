#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10 // Define the maximum number of vertices

// Graph structure
typedef struct {
    int numVertices;
    bool adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix representation
} Graph;

// Function to initialize the graph
void initGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = false; // Initialize all edges to false
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = true;
    graph->adjMatrix[dest][src] = true; // For undirected graph
}

// Function to perform BFS starting from a given source vertex
void BFS(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false}; // Array to track visited vertices
    int queue[MAX_VERTICES]; // Queue for BFS
    int front = 0, rear = 0;

    // Mark the starting vertex as visited and enqueue it
    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear) {
        // Dequeue a vertex and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Enqueue all adjacent vertices that haven't been visited
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    Graph graph;
    initGraph(&graph, 6);

    // Add edges to the graph
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 4, 5);

    printf("Breadth-First Search starting from vertex 0:\n");
    BFS(&graph, 0);

    return 0;
}
