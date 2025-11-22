#include <iostream>
using namespace std;

// structure for one non-zero element
struct Element {
    int row;
    int col;
    int value;
};

// structure for sparse matrix
struct SparseMatrix {
    int rows;          // total rows
    int cols;          // total columns
    int nonZeroCount;  // number of non-zero elements
    Element *elements; // array to store non-zero elements
};

// function to display sparse matrix (triplet form)
void displaySparse(SparseMatrix m) {
    cout << "\nSparse Matrix Representation (row col value):\n";
    for (int i = 0; i < m.nonZeroCount; i++) {
        cout << m.elements[i].row << " "
             << m.elements[i].col << " "
             << m.elements[i].value << endl;
    }
}

// function to display full matrix
void displayFull(SparseMatrix m) {
    cout << "\nFull Matrix form:\n";
    int k = 0;
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            if (k < m.nonZeroCount && m.elements[k].row == i && m.elements[k].col == j) {
                cout << m.elements[k].value << " ";
                k++;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

// function to transpose a sparse matrix
SparseMatrix transpose(SparseMatrix m) {
    SparseMatrix t;
    t.rows = m.cols;
    t.cols = m.rows;
    t.nonZeroCount = m.nonZeroCount;
    t.elements = new Element[t.nonZeroCount];

    int k = 0;
    for (int i = 0; i < m.cols; i++) {
        for (int j = 0; j < m.nonZeroCount; j++) {
            if (m.elements[j].col == i) {
                t.elements[k].row = m.elements[j].col;
                t.elements[k].col = m.elements[j].row;
                t.elements[k].value = m.elements[j].value;
                k++;
            }
        }
    }
    return t;
}

// function to add two sparse matrices
SparseMatrix add(SparseMatrix a, SparseMatrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        cout << "Matrices cannot be added (different dimensions)!" << endl;
        SparseMatrix temp = {0,0,0,nullptr};
        return temp;
    }

    SparseMatrix sum;
    sum.rows = a.rows;
    sum.cols = a.cols;
    sum.elements = new Element[a.nonZeroCount + b.nonZeroCount];

    int i = 0, j = 0, k = 0;
    while (i < a.nonZeroCount && j < b.nonZeroCount) {
        if (a.elements[i].row < b.elements[j].row ||
           (a.elements[i].row == b.elements[j].row && a.elements[i].col < b.elements[j].col)) {
            sum.elements[k++] = a.elements[i++];
        } else if (b.elements[j].row < a.elements[i].row ||
                  (b.elements[j].row == a.elements[i].row && b.elements[j].col < a.elements[i].col)) {
            sum.elements[k++] = b.elements[j++];
        } else {
            // same position → add values
            sum.elements[k] = a.elements[i];
            sum.elements[k++].value = a.elements[i++].value + b.elements[j++].value;
        }
    }
    // copy remaining elements
    while (i < a.nonZeroCount) sum.elements[k++] = a.elements[i++];
    while (j < b.nonZeroCount) sum.elements[k++] = b.elements[j++];

    sum.nonZeroCount = k;
    return sum;
}

// function to multiply two sparse matrices
SparseMatrix multiply(SparseMatrix a, SparseMatrix b) {
    if (a.cols != b.rows) {
        cout << "Matrices cannot be multiplied (invalid dimensions)!" << endl;
        SparseMatrix temp = {0,0,0,nullptr};
        return temp;
    }

    SparseMatrix prod;
    prod.rows = a.rows;
    prod.cols = b.cols;
    prod.nonZeroCount = 0;
    prod.elements = new Element[a.nonZeroCount * b.nonZeroCount]; // worst case

    int k = 0;
    for (int i = 0; i < a.nonZeroCount; i++) {
        for (int j = 0; j < b.nonZeroCount; j++) {
            if (a.elements[i].col == b.elements[j].row) {
                // new element in product
                prod.elements[k].row = a.elements[i].row;
                prod.elements[k].col = b.elements[j].col;
                prod.elements[k].value = a.elements[i].value * b.elements[j].value;
                k++;
            }
        }
    }
    prod.nonZeroCount = k;
    return prod;
}

int main() {
    SparseMatrix A, B;

    // input for first matrix
    cout << "Enter rows, cols and non-zero count of Matrix A: ";
    cin >> A.rows >> A.cols >> A.nonZeroCount;
    A.elements = new Element[A.nonZeroCount];
    cout << "Enter elements (row col value):\n";
    for (int i = 0; i < A.nonZeroCount; i++)
        cin >> A.elements[i].row >> A.elements[i].col >> A.elements[i].value;

    // input for second matrix
    cout << "\nEnter rows, cols and non-zero count of Matrix B: ";
    cin >> B.rows >> B.cols >> B.nonZeroCount;
    B.elements = new Element[B.nonZeroCount];
    cout << "Enter elements (row col value):\n";
    for (int i = 0; i < B.nonZeroCount; i++)
        cin >> B.elements[i].row >> B.elements[i].col >> B.elements[i].value;

    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Display Matrices\n";
        cout << "2. Transpose A\n";
        cout << "3. Transpose B\n";
        cout << "4. A + B\n";
        cout << "5. A * B\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\nMatrix A:";
                displaySparse(A);
                displayFull(A);
                cout << "\nMatrix B:";
                displaySparse(B);
                displayFull(B);
                break;
            case 2: {
                SparseMatrix T = transpose(A);
                cout << "\nTranspose of A:";
                displaySparse(T);
                displayFull(T);
                delete[] T.elements;
                break;
            }
            case 3: {
                SparseMatrix T = transpose(B);
                cout << "\nTranspose of B:";
                displaySparse(T);
                displayFull(T);
                delete[] T.elements;
                break;
            }
            case 4: {
                SparseMatrix S = add(A, B);
                if (S.elements != nullptr) {
                    cout << "\nA + B:";
                    displaySparse(S);
                    displayFull(S);
                    delete[] S.elements;
                }
                break;
            }
            case 5: {
                SparseMatrix M = multiply(A, B);
                if (M.elements != nullptr) {
                    cout << "\nA * B:";
                    displaySparse(M);
                    displayFull(M);
                    delete[] M.elements;
                }
                break;
            }
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 6);

    delete[] A.elements;
    delete[] B.elements;

    return 0;
}