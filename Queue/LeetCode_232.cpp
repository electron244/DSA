#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;

    // Constructor
    MyQueue() {}

    // Push element x to the back of queue
    void push(int x) {
        // Move everything from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element into s1
        s1.push(x);

        // Move everything back from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Removes the element from the front of the queue
    int pop() {
        if (s1.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    // Get the front element
    int peek() {
        if (s1.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return s1.top();
    }

    // Returns whether the queue is empty
    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl;   // 10
    cout << "Popped: " << q.pop() << endl;          // 10
    cout << "Front element now: " << q.peek() << endl; // 20

    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    q.pop();
    q.pop();
    cout << "Is empty now? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
