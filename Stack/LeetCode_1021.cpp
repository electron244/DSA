#include <iostream>
#include <string>
#include <stack>
using namespace std;

string removeOuterParentheses(string s) {
    string result = "";
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (ch == '(') {
            // If stack is not empty, it's not the outermost '('
            if (!st.empty()) {
                result += ch;
            }
            st.push(ch);
        } else { // ch == ')'
            st.pop(); // Remove matching '('
            
            // If stack is not empty, it's not the outermost ')'
            if (!st.empty()) {
                result += ch;
            }
        }
    }

    return result;
}

int main() {
    string s = "(()())(())";
    cout << removeOuterParentheses(s) << endl;  // Output: ()()()
    return 0;
}
