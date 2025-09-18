#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    // Constructor
    MyStack() {}

    // Push element x onto stack
    void push(int x) {
        // Move all elements of q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push new element into q1
        q1.push(x);

        // Move back everything from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Removes the element on top of the stack
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    // Get the top element
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.front();
    }

    // Returns whether the stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;   // 30
    cout << "Popped: " << st.pop() << endl;       // 30
    cout << "Top element now: " << st.top() << endl; // 20

    cout << "Is empty? " << (st.empty() ? "Yes" : "No") << endl;

    st.pop();
    st.pop();
    cout << "Is empty now? " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}
