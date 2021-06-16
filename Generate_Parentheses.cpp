/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
public:
    void solve(int open, int close, string st, vector<string>& res)
    {
        //base case if we exhaust open and close bracket
        if((open == 0) && (close == 0))
        {
            res.push_back(st);
            return;
        }
        
        /*
        there is always case when open bracket needs to add
        ex : "((("
        */
        if(open != 0)
        {
            string op = st;
            op += "(";
            solve(open-1,close,op,res);
        }
        /*
        if we use open bracket and it's count goes below close bracket 
        then we can add close bracket for balance
        for ex : "(("  and ")))"
        combination : 
        (())(), ((())).....
        */
        if(open < close)
        {
            string op1 = st;
            op1 += ")";
            solve(open,close-1,op1,res);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        
        if(n <= 0)
            return res;
        
        int open = n;
        int close = n;
        string st = "";
        
        solve(open,close,st,res);
        return res;
        
    }
};
