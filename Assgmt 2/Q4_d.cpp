#include <iostream>
using namespace std;
int main() {

    //alphabetical order
    string str;
    cout<< "Enter a string: ";
    cin>> str;
    int temp;
    int n = str.length();
    for(int i = 0; i<n-1; i++){
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    cout<<str<<endl;
    return 0;
}