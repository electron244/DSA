#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {
            if(st.empty()) {
                return false;
            }
            if((st.top() == '(' && s[i] == ')') ||
               (st.top() == '{' && s[i] == '}') ||
               (st.top() == '[' && s[i] == ']')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string input;
    input = "({})";
    if(isValid(input)) {
        cout << "The brackets are balanced." << endl;
    } else {
        cout << "The brackets are not balanced." << endl;
    }

    return 0;
}
