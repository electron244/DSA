#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to calculate total points based on the operations
int calPoints(vector<string>& operations) {
    vector<int> stack;
    int sum = 0;

    for (const string& op : operations) {
        if (op == "+") {
            int last = stack[stack.size() - 1];
            int slast = stack[stack.size() - 2];
            stack.push_back(last + slast);
            sum += last + slast;
        } else if (op == "D") {
            int new_score = stack.back() * 2;
            stack.push_back(new_score);
            sum += new_score;
        } else if (op == "C") {
            sum -= stack.back();
            stack.pop_back();
        } else {
            int new_score = stoi(op);
            stack.push_back(new_score);
            sum += new_score;
        }
    }

    return sum;
}

int main() {
    // Example input
    vector<string> operations = {"5", "2", "C", "D", "+"};

    // Call the function
    int total = calPoints(operations);

    // Output the result
    cout << "Total score: " << total << endl;

    return 0;
}
