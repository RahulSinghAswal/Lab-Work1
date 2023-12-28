#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int V = 5; // Number of vertices in the graph

// Function to find the vertex with the minimum key value
int minKey(const vector<int>& key, const vector<bool>& mstSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(const vector<int>& parent, const vector<vector<int>>& graph) {
    cout << "Edge   Weight" << endl;
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "    " << graph[i][parent[i]] << endl;
}

// Function to construct and print MST for a graph using Prim's algorithm
void primMST(const vector<vector<int>>& graph) {
    vector<int> parent(V); // To store constructed MST
    vector<int> key(V); // Key values used to pick the minimum weight edge

    vector<bool> mstSet(V, false); // To represent set of vertices included in MST

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
    }

    // Start with the first vertex
    key[0] = 0; // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // Pick the minimum key vertex not yet included in MST
        mstSet[u] = true; // Include the picked vertex in MST

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    cout << "Minimum Cost Spanning Tree (MST) using Prim's algorithm:" << endl;
    primMST(graph);

    return 0;
}
