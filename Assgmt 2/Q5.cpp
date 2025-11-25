#include <iostream>
#include <vector>
using namespace std;

// ----------- Diagonal Matrix -------------
class DiagonalMatrix {
    vector<int> diag;
    int n;
public:
    DiagonalMatrix(int size) : n(size) {
        diag.resize(n);
    }

    void set(int i, int j, int val) {
        if (i == j) diag[i] = val;
    }

    int get(int i, int j) {
        if (i == j) return diag[i];
        return 0;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << get(i, j) << " ";
            cout << endl;
        }
    }
};

// ----------- Tri-Diagonal Matrix -------------
class TriDiagonalMatrix {
    vector<int> tri;  // 3n - 2 elements
    int n;
public:
    TriDiagonalMatrix(int size) : n(size) {
        tri.resize(3*n - 2);
    }

    void set(int i, int j, int val) {
        if (i == j) tri[i] = val;
        else if (i == j-1) tri[n+i] = val;
        else if (i-1 == j) tri[2*n-1+j] = val;
    }

    int get(int i, int j) {
        if (i == j) return tri[i];
        else if (i == j-1) return tri[n+i];
        else if (i-1 == j) return tri[2*n-1+j];
        else return 0;
    }

    void display() {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++)
                cout << get(i,j) << " ";
            cout << endl;
        }
    }
};

// ----------- Lower Triangular Matrix -------------
class LowerTriangularMatrix {
    vector<int> lower; // n(n+1)/2 elements
    int n;
public:
    LowerTriangularMatrix(int size): n(size) {
        lower.resize(n*(n+1)/2);
    }

    void set(int i, int j, int val) {
        if (i >= j) 
            lower[i*(i+1)/2 + j] = val;
    }

    int get(int i, int j) {
        if (i >= j) 
            return lower[i*(i+1)/2 + j];
        return 0;
    }

    void display() {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++)
                cout << get(i,j) << " ";
            cout << endl;
        }
    }
};

// ----------- Upper Triangular Matrix -------------
class UpperTriangularMatrix {
    vector<int> upper; // n(n+1)/2 elements
    int n;
public:
    UpperTriangularMatrix(int size): n(size) {
        upper.resize(n*(n+1)/2);
    }

    void set(int i, int j, int val) {
        if (i <= j) 
            upper[j*(j+1)/2 + i] = val;
    }

    int get(int i, int j) {
        if (i <= j) 
            return upper[j*(j+1)/2 + i];
        return 0;
    }

    void display() {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++)
                cout << get(i,j) << " ";
            cout << endl;
        }
    }
};

// ----------- Symmetric Matrix -------------
class SymmetricMatrix {
    vector<int> sym; // n(n+1)/2 elements
    int n;
public:
    SymmetricMatrix(int size): n(size) {
        sym.resize(n*(n+1)/2);
    }

    void set(int i, int j, int val) {
        if (i >= j) sym[i*(i+1)/2 + j] = val;
        else sym[j*(j+1)/2 + i] = val;
    }

    int get(int i, int j) {
        if (i >= j) return sym[i*(i+1)/2 + j];
        else return sym[j*(j+1)/2 + i];
    }

    void display() {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++)
                cout << get(i,j) << " ";
            cout << endl;
        }
    }
};

// ---------------- Main ----------------
int main() {
    int n, choice;
    cout << "Enter size of matrix: ";
    cin >> n;

    cout << "Choose matrix type:\n";
    cout << "1. Diagonal Matrix\n";
    cout << "2. Tri-Diagonal Matrix\n";
    cout << "3. Lower Triangular Matrix\n";
    cout << "4. Upper Triangular Matrix\n";
    cout << "5. Symmetric Matrix\n";
    cin >> choice;

    switch(choice) {
        case 1: {
            DiagonalMatrix m(n);
            cout << "Enter diagonal elements:\n";
            for (int i=0;i<n;i++) {
                int val; cin >> val;
                m.set(i,i,val);
            }
            m.display();
            break;
        }
        case 2: {
            TriDiagonalMatrix m(n);
            cout << "Enter diagonal elements:\n";
            for (int i=0;i<n;i++) {
                int val; cin >> val;
                m.set(i,i,val);
            }
            cout << "Enter upper diagonal elements:\n";
            for (int i=0;i<n-1;i++) {
                int val; cin >> val;
                m.set(i,i+1,val);
            }
            cout << "Enter lower diagonal elements:\n";
            for (int i=0;i<n-1;i++) {
                int val; cin >> val;
                m.set(i+1,i,val);
            }
            m.display();
            break;
        }
        case 3: {
            LowerTriangularMatrix m(n);
            cout << "Enter lower triangular elements row by row:\n";
            for (int i=0;i<n;i++) {
                for (int j=0;j<=i;j++) {
                    int val; cin >> val;
                    m.set(i,j,val);
                }
            }
            m.display();
            break;
        }
        case 4: {
            UpperTriangularMatrix m(n);
            cout << "Enter upper triangular elements row by row:\n";
            for (int i=0;i<n;i++) {
                for (int j=i;j<n;j++) {
                    int val; cin >> val;
                    m.set(i,j,val);
                }
            }
            m.display();
            break;
        }
        case 5: {
            SymmetricMatrix m(n);
            cout << "Enter lower triangular elements row by row (since symmetric):\n";
            for (int i=0;i<n;i++) {
                for (int j=0;j<=i;j++) {
                    int val; cin >> val;
                    m.set(i,j,val);
                }
            }
            m.display();
            break;
        }
        default:
            cout << "Invalid choice!\n";
    }

    return 0;
}