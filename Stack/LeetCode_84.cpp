#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to calculate the largest rectangle area
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;             // Stack to store indices of bars
    heights.push_back(0);     // Append 0 to process all remaining bars
    int maxArea = 0;          // Variable to keep track of maximum area

    for (int i = 0; i < heights.size(); ++i) {
        // Process while the current bar is smaller than the bar at stack top
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int height = heights[st.top()];  // Get the height of the bar
            st.pop();                        // Pop the bar
            int width = st.empty() ? i : i - st.top() - 1;  // Calculate width
            maxArea = max(maxArea, height * width);         // Update max area
        }
        st.push(i); // Push current index onto the stack
    }

    return maxArea; // Return the largest rectangle area found
}

int main() {
    int n;
    n = 6;
    vector<int> heights(n);
    heights = {2,1,5,6,2,3};
    int result = largestRectangleArea(heights); // Call the function
    cout << "Largest Rectangle Area: " << result << endl; // Output the result

    return 0;
}
