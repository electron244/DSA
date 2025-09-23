#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> m;
    queue<int> Q;

    for (int i = 0; i < s.size(); i++) {
        if (m.find(s[i]) == m.end()) {
            Q.push(i);
        }
        m[s[i]]++;

        while (!Q.empty() && m[s[Q.front()]] > 1) {
            Q.pop();
        }
    }

    return Q.empty() ? -1 : Q.front();
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int index = firstUniqChar(s);

    if (index == -1) {
        cout << "No unique character found." << endl;
    } else {
        cout << "First unique character is '" << s[index] << "' at index " << index << endl;
    }

    return 0;
}
