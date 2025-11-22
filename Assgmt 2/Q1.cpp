#include <iostream>
using namespace std;

// Linear Search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int target) {
    int beg = 0, end = n - 1;

    while (beg <= end) {
        int mid = (beg + end)/2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
         beg = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main() {
    
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr);
    int target;

    cout << "Enter the number to search: ";
    cin >> target;

    // Linear Search
    int linear = linearSearch(arr, n, target);
    if (linear != -1)
        cout << "Linear Search: Element found at index " << linear << endl;
    else
        cout << "Linear Search: Element not found" << endl;

    // Binary Search
    int binary = binarySearch(arr, n, target);
    if (binary != -1)
        cout << "Binary Search: Element found at index " << binary << endl;
    else
        cout << "Binary Search: Element not found" << endl;

    return 0;
}
