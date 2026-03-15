/**
 * Binary Search Implementation in C++
 * 
 * This file contains:
 * 1. Iterative Binary Search
 * 2. Recursive Binary Search
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1) for iterative, O(log n) for recursive
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Iterative Binary Search
 * @param arr - sorted array to search in
 * @param target - element to search for
 * @return index of target if found, -1 otherwise
 */
int binarySearchIterative(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoids potential overflow

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;  // Target not found
}

/**
 * Recursive Binary Search
 * @param arr - sorted array to search in
 * @param left - left boundary index
 * @param right - right boundary index
 * @param target - element to search for
 * @return index of target if found, -1 otherwise
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

/**
 * Lower Bound - finds the first position where target could be inserted
 * @param arr - sorted array
 * @param target - element to find lower bound for
 * @return index of the first element >= target
 */
int lowerBound(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

/**
 * Upper Bound - finds the first position after the last occurrence of target
 * @param arr - sorted array
 * @param target - element to find upper bound for
 * @return index of the first element > target
 */
int upperBound(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int target;

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // --- Iterative Binary Search ---
    target = 23;
    int resultIterative = binarySearchIterative(arr, target);
    if (resultIterative != -1) {
        cout << "\n[Iterative] Element " << target << " found at index " << resultIterative << endl;
    } else {
        cout << "\n[Iterative] Element " << target << " not found in the array." << endl;
    }

    // --- Recursive Binary Search ---
    target = 56;
    int resultRecursive = binarySearchRecursive(arr, 0, arr.size() - 1, target);
    if (resultRecursive != -1) {
        cout << "[Recursive] Element " << target << " found at index " << resultRecursive << endl;
    } else {
        cout << "[Recursive] Element " << target << " not found in the array." << endl;
    }

    // --- Lower Bound ---
    target = 16;
    int lb = lowerBound(arr, target);
    cout << "\n[Lower Bound] First position >= " << target << " is index " << lb << endl;

    // --- Upper Bound ---
    int ub = upperBound(arr, target);
    cout << "[Upper Bound] First position > " << target << " is index " << ub << endl;

    // --- Search for a non-existent element ---
    target = 100;
    int resultNotFound = binarySearchIterative(arr, target);
    if (resultNotFound != -1) {
        cout << "\n[Iterative] Element " << target << " found at index " << resultNotFound << endl;
    } else {
        cout << "\n[Iterative] Element " << target << " not found in the array." << endl;
    }

    return 0;
}
