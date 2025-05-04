#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10 // Define maximum number of vertices

// Structure for the graph
typedef struct {
    int numVertices;
    int** adjMatrix;
} Graph;

// Function to create a graph
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // Allocate memory for adjacency matrix
    graph->adjMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0; // Initialize all edges to 0
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int i, int j) {
    graph->adjMatrix[i][j] = 1;
    graph->adjMatrix[j][i] = 1; // For undirected graph
}

// Function to remove an edge from the graph
void removeEdge(Graph* graph, int i, int j) {
    graph->adjMatrix[i][j] = 0;
    graph->adjMatrix[j][i] = 0; // For undirected graph
}

// Function to print the adjacency matrix representation of the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d : ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free allocated memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

int main() {
    Graph* graph = createGraph(4);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);

    freeGraph(graph); // Free allocated memory

    return 0;
}
