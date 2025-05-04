#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10 // Define the maximum number of vertices

// Graph structure with adjacency lists
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES]; // Array of adjacency lists
} Graph;

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the graph
void initGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Recursive DFS utility function
void DFSUtil(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFSUtil(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform DFS starting from a given vertex
void DFS(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false}; // Array to track visited vertices
    DFSUtil(graph, startVertex, visited);
}

// Function to free allocated memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
}

// Main function
int main() {
    Graph graph;
    initGraph(&graph, 6);

    // Add edges to the graph
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 5);

    printf("Depth-First Search starting from vertex 0:\n");
    DFS(&graph, 0);

    freeGraph(&graph); // Free allocated memory

    return 0;
}
