#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {

        int left = 0, right = 0;
        int maxLen = 0;

        //left to right 
        for (char ch : s) {

            if (ch == '(')
                left++;
            else
                right++;

            if (left == right) {
                maxLen = max(maxLen, 2 * right);
            }
            else if (right > left) {
                left = right = 0;
            }
        }

        // Reset counters
        left = right = 0;

        // Right to Left Traversal
        for (int i = s.size() - 1; i >= 0; i--) {

            if (s[i] == '(')
                left++;
            else
                right++;

            if (left == right) {
                maxLen = max(maxLen, 2 * left);
            }
            else if (left > right) {
                left = right = 0;
            }
        }

        return maxLen;
    }
};

int main() {

    Solution obj;
    string s;

    cout << "Enter the parentheses string: ";
    cin >> s;

    int ans = obj.longestValidParentheses(s);

    cout << "Length of the longest valid parentheses substring: " << ans << endl;

    return 0;
}