#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Function to calculate the total distance for a given path
int calculatePathDistance(const vector<vector<int>>& graph, const vector<int>& path) {
    int totalDistance = 0;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        if (graph[path[i]][path[i + 1]] == INF) {
            return INF; // Invalid path
        }
        totalDistance += graph[path[i]][path[i + 1]];
    }
    // Add distance from last city back to the starting city
    totalDistance += graph[path.back()][path[0]];
    return totalDistance;
}

// Function to perform the brute-force approach for TSP
void travelingSalesman(const vector<vector<int>>& graph, int startCity) {
    int numCities = graph.size();
    vector<int> path(numCities);
    for (int i = 0; i < numCities; ++i) {
        path[i] = i;
    }

    int minPath = INF;
    vector<int> minPathOrder;

    // Finding all permutations of paths
    do {
        int currentPathDistance = calculatePathDistance(graph, path);
        if (currentPathDistance < minPath) {
            minPath = currentPathDistance;
            minPathOrder = path;
        }
    } while (next_permutation(path.begin() + 1, path.end())); // Start from index 1, as index 0 is the starting city

    // Print the minimum distance path
    cout << "Minimum Distance: " << minPath << endl;
    cout << "Path: ";
    for (int city : minPathOrder) {
        cout << city << " ";
    }
    cout << minPathOrder[0] << endl; // Returning to the starting city
}

int main() {
    // Example graph (adjacency matrix representing distances between cities)
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int startCity = 0; // Starting city index
    travelingSalesman(graph, startCity);

    return 0;
}
