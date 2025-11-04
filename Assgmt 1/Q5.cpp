//Q5
#include <iostream>
using namespace std;

int main() {
    int arr[10][10];
    int rows, cols;

    // Input dimensions
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Input elements
    cout << "Enter elements of the matrix:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    // Sum of each row
    cout << "\nSum of each row:\n";
    for(int i = 0; i < rows; i++) {
        int rowSum = 0;
        for(int j = 0; j < cols; j++) {
            rowSum += arr[i][j];
        }
        cout << "Row " << i << " sum = " << rowSum << endl;
    }

    // Sum of each column
    cout << "\nSum of each column:\n";
    for(int j = 0; j < cols; j++) {
        int colSum = 0;
        for(int i = 0; i < rows; i++) {
            colSum += arr[i][j];
        }
        cout << "Column " << j << " sum = " << colSum << endl;
    }

    return 0;
}
