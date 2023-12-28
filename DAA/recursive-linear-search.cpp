#include <iostream>
#include <vector>

using namespace std;

// Recursive linear search function
int recursiveLinearSearch(const vector<int>& arr, int index, int target) {
    // Base case: if the index goes beyond the array size, return -1 (element not found)
    if (index >= arr.size())
        return -1;

    // If the current element matches the target, return the current index
    if (arr[index] == target)
        return index;

    // Recursive call with the next index
    return recursiveLinearSearch(arr, index + 1, target);
}

int main() {
    vector<int> arr = {3, 9, 4, 2, 7, 5};
    int target = 7;

    int result = recursiveLinearSearch(arr, 0, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array" << endl;

    return 0;
}
