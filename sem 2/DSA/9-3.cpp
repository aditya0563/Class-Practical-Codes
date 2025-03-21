#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V; // Number of vertices
    list<int>* adj; // Adjacency list

    // Utility function to perform DFS
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

// Constructor to initialize the graph
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

// Function to add an edge to the graph
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v's list
}

// Utility function to perform DFS
void Graph::DFSUtil(int v, bool visited[]) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(*i, visited);
        }
    }
}

// Function to perform DFS starting from a given vertex
void Graph::DFS(int v) {
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Call the recursive helper function to perform DFS
    DFSUtil(v, visited);

    delete[] visited;
}

int main() {
    // Create a graph with 6 vertices
    Graph g(6);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "Depth-First Search starting from vertex 0:" << endl;
    g.DFS(0);

    return 0;
}
