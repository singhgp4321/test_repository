#include <iostream>
#include <vector>
using namespace std;

/**
 * Binary Search Algorithm
 * 
 * Searches for a target value in a sorted array.
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * 
 * @param arr    - sorted vector of integers
 * @param target - the value to search for
 * @return       - index of the target if found, otherwise -1
 */
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoids potential overflow

        if (arr[mid] == target) {
            return mid;           // Target found
        } else if (arr[mid] < target) {
            left = mid + 1;       // Search in the right half
        } else {
            right = mid - 1;      // Search in the left half
        }
    }

    return -1;  // Target not found
}

/**
 * Recursive Binary Search
 * 
 * @param arr    - sorted vector of integers
 * @param left   - left boundary index
 * @param right  - right boundary index
 * @param target - the value to search for
 * @return       - index of the target if found, otherwise -1
 */
int binarySearchRecursive(const vector<int>& arr, int left, int right, int target) {
    if (left > right) {
        return -1;  // Base case: target not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, right, target);
    } else {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // --- Iterative Binary Search ---
    cout << "\n--- Iterative Binary Search ---" << endl;

    int target1 = 23;
    int result1 = binarySearch(arr, target1);
    if (result1 != -1) {
        cout << "Element " << target1 << " found at index " << result1 << endl;
    } else {
        cout << "Element " << target1 << " not found in the array." << endl;
    }

    int target2 = 50;
    int result2 = binarySearch(arr, target2);
    if (result2 != -1) {
        cout << "Element " << target2 << " found at index " << result2 << endl;
    } else {
        cout << "Element " << target2 << " not found in the array." << endl;
    }

    // --- Recursive Binary Search ---
    cout << "\n--- Recursive Binary Search ---" << endl;

    int target3 = 56;
    int result3 = binarySearchRecursive(arr, 0, arr.size() - 1, target3);
    if (result3 != -1) {
        cout << "Element " << target3 << " found at index " << result3 << endl;
    } else {
        cout << "Element " << target3 << " not found in the array." << endl;
    }

    int target4 = 100;
    int result4 = binarySearchRecursive(arr, 0, arr.size() - 1, target4);
    if (result4 != -1) {
        cout << "Element " << target4 << " found at index " << result4 << endl;
    } else {
        cout << "Element " << target4 << " not found in the array." << endl;
    }

    return 0;
}
