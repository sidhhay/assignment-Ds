#include <iostream>
using namespace std;

// (a) Linear Time
int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1)
            return i + 1;
    }
    return n;
}

// (b) Binary Search:
int findMissingBinary(int arr[], int n) {
    int beg = 0, end = n - 2;
    while (beg <= end) {
        int mid = (beg + end) / 2;

        if (arr[mid] == mid + 1)
            beg = mid + 1;
        else
            end = mid - 1;
    }
    return beg + 1;
}

int main() {
    
    int arr[] = {1, 2, 3, 4, 6};
    int n = 6;

    cout << "Linear Time Missing Number: " << findMissingLinear(arr, n) << endl;
    cout << "Binary Search Missing Number: " << findMissingBinary(arr, n) << endl;

    return 0;
}
