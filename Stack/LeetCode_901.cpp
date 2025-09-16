#include <iostream>
#include <stack>
using namespace std;

// Global stack to store (price, span)
stack<pair<int, int>> st;

// Initialize function
void initialize() {
    while (!st.empty()) {
        st.pop();  // Clear the stack if needed
    }
}

// Function to process next price and return the span
int next(int price) {
    int span = 1;
    
    // Combine spans while the last price is less or equal to current price
    while (!st.empty() && st.top().first <= price) {
        span += st.top().second;
        st.pop();
    }
    
    st.push({price, span});
    return span;
}

int main() {
    initialize();
    
    // Example usage:
    cout << next(100) << endl;  // Output: 1
    cout << next(80) << endl;   // Output: 1
    cout << next(60) << endl;   // Output: 1
    cout << next(70) << endl;   // Output: 2
    cout << next(60) << endl;   // Output: 1
    cout << next(75) << endl;   // Output: 4
    cout << next(85) << endl;   // Output: 6

    return 0;
}
