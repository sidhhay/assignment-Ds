//Q4 (a)
#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
    for(int i = 0; i < n/2; i++) {
        // Swap arr[i] and arr[n - i - 1]
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

int main() {
    int arr[100], n;

    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    reverseArray(arr, n);

    cout << "Reversed Array:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}