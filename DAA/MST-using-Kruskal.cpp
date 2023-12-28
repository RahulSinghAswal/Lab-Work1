#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int source, destination, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E; // Number of vertices and edges
    vector<Edge> edges; // Vector to store edges of the graph

    // Constructor
    Graph(int v, int e) {
        V = v;
        E = e;
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        Edge edge;
        edge.source = src;
        edge.destination = dest;
        edge.weight = weight;
        edges.push_back(edge);
    }

    // Utility function to find the subset of an element i
    int find(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    // Utility function to do union of two subsets
    void Union(vector<int>& parent, int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }

    // Function to find Minimum Spanning Tree using Kruskal's algorithm
    void KruskalMST() {
        // Resultant MST vector to store the edges of MST
        vector<Edge> resultMST;

        // Sort all the edges in non-decreasing order of their weight
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        // Allocate memory for creating V subsets
        vector<int> parent(V, -1);

        int edgeCount = 0;
        int i = 0; // Index variable used for sorted edges

        // MST contains V-1 edges
        while (edgeCount < V - 1 && i < E) {
            Edge nextEdge = edges[i++];
            int x = find(parent, nextEdge.source);
            int y = find(parent, nextEdge.destination);

            // If including this edge does not cause a cycle, include it in the result
            if (x != y) {
                resultMST.push_back(nextEdge);
                Union(parent, x, y);
                edgeCount++;
            }
        }

        // Print the constructed MST
        cout << "Edges of Minimum Spanning Tree (MST):" << endl;
        for (const auto& edge : resultMST) {
            cout << edge.source << " - " << edge.destination << " : " << edge.weight << endl;
        }
    }
};

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges

    // Create a graph
    Graph graph(V, E);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    // Find Minimum Spanning Tree (MST) using Kruskal's algorithm
    graph.KruskalMST();

    return 0;
}
