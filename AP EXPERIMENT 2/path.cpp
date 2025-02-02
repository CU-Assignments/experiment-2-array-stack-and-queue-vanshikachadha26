#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        deque<string> stack;

        // Split the path into components by '/'
        while (getline(ss, token, '/')) {
            if (token.empty() || token == ".") {
                // Skip empty or current directory (.)
                continue;
            } else if (token == "..") {
                // Go up one directory if possible (pop from the stack)
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                // Add valid directory name to the stack
                stack.push_back(token);
            }
        }

        // If the stack is empty, return the root directory "/"
        if (stack.empty()) {
            return "/";
        }

        // Build the simplified path from the stack
        string result = "";
        for (const string& dir : stack) {
            result += "/" + dir;
        }

        return result;
    }
};

int main() {
    Solution solution;
    string path = "/home/../usr/./bin/";
    cout << solution.simplifyPath(path) << endl;  // Output: "/usr/bin"
    return 0;
}
