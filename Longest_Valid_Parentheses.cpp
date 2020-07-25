/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        
        if(n == 0)
            return 0;
        
        int len = 0;
        stack<int> st;
        //initializing stack
        st.push(-1);
        
        for(int i = 0; i < n; i++)
        {
            //if '(' encounters then push it's index in stack
            if(s[i] == '(')
                st.push(i);
            
            else
            {
                //remove elements from stack
                st.pop();
                //if stack is empty then add current index
                if(st.empty())
                    st.push(i);
                
                else
                {
                    //find max of len and (curr index - top of stack)
                    len = max(len,i-st.top());
                }
            }
        }
        return len;
    }
};
