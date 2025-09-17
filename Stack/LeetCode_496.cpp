#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st; // stores indices

    for (int i = 0; i < 2 * n; ++i) {
        int index = i % n;

        while (!st.empty() && nums[st.top()] < nums[index]) {
            result[st.top()] = nums[index];
            st.pop();
        }

        if (i < n) {
            st.push(index);
        }
    }

    return result;
}

int main() {
    // Example input
    vector<int> nums = {1, 2, 1};

    // Call the function
    vector<int> result = nextGreaterElements(nums);

    // Output the result
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
