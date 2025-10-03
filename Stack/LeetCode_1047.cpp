#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                st.pop(); // remove duplicate
            } else {
                st.push(c);
            }
        }
        // build the final result
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    string s = "abbaca";
    cout << sol.removeDuplicates(s) << endl; // Output: "ca"
    return 0;
}
