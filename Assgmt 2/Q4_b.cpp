#include <iostream>
using namespace std;
int main(){

//Reverse
string str1, str2;
    cout<<"Enter first string: "<<endl;
    getline(cin, str1);
    int n = str1.length();
    
    int temp;
    for(int i=0; i<n/2; i++){
        temp = str1[i];
        str1[i] = str1[n - i - 1];
        str1[n - i - 1] = temp;
    }
    cout << "Reversed string: " << str1 << endl;
    return 0;

}