//Q2
#include <iostream>
using namespace std;

void removeDuplicates(int arr[], int &n) {
    if (n == 0 || n == 1)
        return;

    int temp[n]; // 
    int j = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

    
        for (int k = 0; k < j; k++) {
            if (arr[i] == temp[k]) {
                isDuplicate = true;
                break;
            }
        }

    
        if (!isDuplicate) {
            temp[j] = arr[i];
            j++;
        }
    }

    
    for (int i = 0; i < j; i++) {
        arr[i] = temp[i];
    }

    n = j; 
}

int main() {
    int arr[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    removeDuplicates(arr, n);

    cout << "Array after removing duplicates:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}