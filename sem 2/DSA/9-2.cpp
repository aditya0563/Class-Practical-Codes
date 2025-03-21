#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V; // Number of vertices
    list<int>* adj; // Adjacency list

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
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

// Function to perform BFS starting from a given source vertex
void Graph::BFS(int s) {
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Create a queue for BFS
    queue<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push(s);

    while (!queue.empty()) {
        // Dequeue a vertex from the queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop();

        // Get all adjacent vertices of the dequeued vertex s
        // If an adjacent vertex has not been visited, mark it visited and enqueue it
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push(*i);
            }
        }
    }

    delete[] visited;
}

int main() {
    // Create a graph with 6 vertices
    Graph g(6);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    cout << "Breadth-First Search starting from vertex 0:" << endl;
    g.BFS(0);

    return 0;
}
