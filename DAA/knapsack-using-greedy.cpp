#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent each item with its weight and value
struct Item {
    int weight;
    int value;
    double ratio; // Ratio of value to weight
};

// Function to compare items based on their ratio (value-to-weight ratio)
bool compare(Item i1, Item i2) {
    return i1.ratio > i2.ratio;
}

// Function to solve the fractional Knapsack Problem
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Sort items based on their value-to-weight ratio in non-increasing order
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (auto& item : items) {
        if (capacity <= 0)
            break;

        // Take the whole item if capacity is greater than or equal to its weight
        if (capacity >= item.weight) {
            totalValue += item.value;
            capacity -= item.weight;
        } else { // Take a fraction of the item
            double fraction = static_cast<double>(capacity) / item.weight;
            totalValue += (fraction * item.value);
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items = {
        {10, 60, 0.0}, // Weight, Value, Ratio
        {20, 100, 0.0},
        {30, 120, 0.0}
    };

    int capacity = 50;

    for (auto& item : items) {
        item.ratio = static_cast<double>(item.value) / item.weight;
    }

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value in Knapsack: " << maxValue << endl;

    return 0;
}
