#include <iostream>
using namespace std;

int countInversions(int A[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) count++;
        }
    }
    return count;
}

int main() {
    int A[] = {8, 4, 2, 1};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Number of inversions: " << countInversions(A, n) << endl;
    return 0;
}
