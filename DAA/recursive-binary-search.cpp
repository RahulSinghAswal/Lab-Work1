#include <iostream>
#include <vector>

using namespace std;

// Recursive binary search function
int binarySearch(const vector<int>& arr, int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == target)
            return mid;

        // If the element is smaller than the middle element, then it can only be present in the left subarray
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);

        // Else the element can only be present in the right subarray
        return binarySearch(arr, mid + 1, right, target);
    }

    // Element is not present in the array
    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    int n = arr.size();

    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array" << endl;

    return 0;
}
