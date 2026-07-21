The brute force solution would generate every substringa and then validate each of them , so in this case the time complexity would be O(n^3), which would not work well for the given constraint:0 <= s.length <= 3 * 104

The submitted solution includes the better and the optimal approaches .
##Better Approach:
It uses stack,and process the string in a single traversal by storing the indices of opening parentheses.

1.Initialize the stack with -1. This acts as the starting boundary for the first valid substring.
2.Traverse the string from left to right.
3.If the current character is an opening parenthesis, push its index onto the stack.
4.If the current character is a closing parenthesis, pop the top element from the stack.
5.If the stack becomes empty after popping, push the current index onto the stack. This index becomes the new starting boundary for the next possible valid substring.
6.Otherwise, calculate the length of the current valid substring using:
7.currentIndex - stack.top()
8.Keep updating the maximum length found during the traversal.

Time Complexity: O(n)

Space Complexity: O(n)


##optimal Approach 
Two Pointer Approach .
1.we will maintain two pointers left and right bith strating from the index 0.
2.We will traverse the string from left to right ,if its a opening bracket ,increment left,otheriwse if its closing increment right.
3.whenever the left and right becomes equal the valid substring is found,update the ans with 2*right.
4.if right becomes greater than left, reset both to 0,since no valid substring can continue from that point.
The left-to-right traversal correctly handles cases where there are extra closing parentheses. However, it fails when there are extra opening parentheses at the end of the string.

For example:

(()

The longest valid substring is (), but the left-to-right traversal does not detect it because the number of opening parentheses is greater than the number of closing parentheses.

To handle such cases, we perform another traversal from right to left.

1.Reset both left and right counters to 0.
2.Traverse the string from right to left.
3.If the current character is an opening parenthesis, increment left.
4.Otherwise, increment right.
5.Whenever left and right become equal, update the maximum length.
6.If left becomes greater than right, reset both counters to 0, since no valid substring can continue beyond that point.

By scanning the string in both directions, we would be able to handle both extra opening and closing parentheses and get the length of the longest valid parentheses substring.

Time Complexity: O(n)

Space Complexity: O(1)
