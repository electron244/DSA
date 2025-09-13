#include <iostream>
#include <vector>
#include <algorithm> // for max()

using namespace std;

// Function to calculate trapped rain water
int trap(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int lmax = 0, rmax = 0;
    int ans = 0;

    while(l < r) {
        lmax = max(lmax, height[l]);
        rmax = max(rmax, height[r]);

        if(lmax < rmax) {
            ans += lmax - height[l];
            l++;
        } else {
            ans += rmax - height[r];
            r--;
        }
    }
    return ans;
}

int main() {
    // Example input
    vector<int> height = {4,2,0,3,2,5};

    // Call the trap function
    int result = trap(height);

    // Print the result
    cout << "Trapped water: " << result << endl;

    return 0;
}
