#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        //tc is O(2N)=O(N) where N is the lenth of string and sc is O(1)

        int l= 0, r = 0;
        int maxlength = 0;

        //left to right 
        for (char ch : s) {

            if (ch == '(')
                l++;
            else
                r++;

            if (l == r) {
                maxlength = max(maxlength, 2 * r);
            }
            else if (r > l) {
                l = r = 0;
            }
        }

        // Reset counters
        l = r = 0;

        //second pass right to left traversal 
        for (int i = s.size() - 1; i >= 0; i--) {

            if (s[i] == '(')
                l++;
            else
                r++;

            if (l == r) {
                maxlength = max(maxlength, 2 * l);
            }
            else if (l > r) {
                l = r = 0;
            }
        }

        return maxlength;
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
