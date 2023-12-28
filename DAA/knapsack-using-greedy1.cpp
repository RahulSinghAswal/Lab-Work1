#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item a, Item b) {
    return (a.value > b.value);
}

int knapsackGreedy(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    int totalValue = 0;
    for (const auto& item : items) {
        if (capacity >= item.weight) {
            totalValue += item.value;
            capacity -= item.weight;
        }
    }
    return totalValue;
}

int main() {
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}}; // Example items (weight, value)
    int knapsackCapacity = 50; // Knapsack capacity

    int maxValue = knapsackGreedy(knapsackCapacity, items);
    cout << "Maximum value in Knapsack (Greedy): " << maxValue << endl;

    return 0;
}
