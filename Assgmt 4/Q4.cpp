#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    
    queue<char> q;
    unordered_map<char,int> freq;

    for (char ch : input) {
        if (ch == ' ') continue;

        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }

    return 0;
}
