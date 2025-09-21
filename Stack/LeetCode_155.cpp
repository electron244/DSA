#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<long long int> minStack;
    long long int minVal;

    MinStack() {}

    void push(int val) {
        if (minStack.empty()) {
            minStack.push(val);
            minVal = val;
        } else {
            if (val < minVal) {
                // store modified value
                minStack.push((long long)2 * val - minVal);
                minVal = val;
            } else {
                minStack.push(val);
            }
        }
    }

    void pop() {
        if (minStack.top() < minVal) {
            // retrieve old minVal
            minVal = 2 * minVal - minStack.top();
        }
        minStack.pop();
    }

    int top() {
        if (minStack.top() < minVal) {
            return minVal;
        }
        return minStack.top();
    }

    int getMin() {
        return minVal;
    }
};

int main() {
    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Current Min: " << st.getMin() << endl; // should print 2
    cout << "Top element: " << st.top() << endl;    // should print 2

    st.pop();
    cout << "After one pop, Min: " << st.getMin() << endl; // should print 3
    cout << "Top element: " << st.top() << endl;           // should print 7

    st.pop();
    cout << "After another pop, Min: " << st.getMin() << endl; // should print 3
    cout << "Top element: " << st.top() << endl;               // should print 3

    return 0;
}
