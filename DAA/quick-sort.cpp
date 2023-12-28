#include <iostream>
#include <vector>

using namespace std;

// Partition the array using the last element as pivot
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Pivot element
    int i = low - 1;  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;  // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(const vector<int>& arr) {
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Original array: ";
    printArray(arr);

    int n = arr.size();
    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
