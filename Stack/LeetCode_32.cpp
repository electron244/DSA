#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; // store indices of '('
        st.push(-1);   // base index for calculations
        int max_len = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(i); // store index of '('
            } else {
                st.pop(); // attempt to match with '('
                if(st.empty()) {
                    st.push(i); // unmatched ')', reset base index
                } else {
                    max_len = max(max_len, i - st.top()); // calculate valid length
                }
            }
        }
        return max_len;
    }
};

int main() {
    Solution solution;
    string s;

    s = ")()()"; // Example input

    int result = solution.longestValidParentheses(s);

    cout << "Longest valid parentheses length is: " << result << endl;

    return 0;
}
