#include <iostream>
#include <list>
using namespace std;

class Graph {
    int numVertices;
    list<int>* adjLists;

public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjLists = new list<int>[numVertices];
    }

    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src); // For undirected graph
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << " : ";
            for (int adj : adjLists[i]) {
                cout << adj << " ";
            }
            cout << endl;
        }
    }

    ~Graph() {
        delete[] adjLists;
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.printGraph();

    return 0;
}
