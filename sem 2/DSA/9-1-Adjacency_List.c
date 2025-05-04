#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10 // Define max number of vertices

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure for adjacency list
typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES]; // Array of adjacency lists
} Graph;

// Function to create a graph
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to an undirected graph
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

// Function to print the adjacency list representation of the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d : ", i);
        Node* temp = graph->adjLists[i];
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
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
