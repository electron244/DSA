#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to process the string by applying backspace rules
string buildString(const string& str) {
    vector<char> stack;
    for(char c : str) {
        if(c != '#') {
            stack.push_back(c);
        } else {
            if(!stack.empty()) {
                stack.pop_back();
            }
        }
    }
    return string(stack.begin(), stack.end());
}

// Function to compare two strings after applying backspaces
bool backspaceCompare(string s, string t) {
    return buildString(s) == buildString(t);
}

int main() {
    // Example inputs
    string s = "ab#c";
    string t = "ad#c";
    
    if(backspaceCompare(s, t)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
