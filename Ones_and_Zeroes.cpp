/*
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 

Constraints:

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        
        int arr_length = strs.size();
        
        int **dp = new int*[m+1];
        for(int i = 0; i <= m; i++)
            dp[i] = new int[n+1];
        
        for(int i = 0; i <= m; i++)
            for(int j = 0; j <= n; j++)
                dp[i][j] = 0;

        int one=0,zero=0;
        int res=0;
        for(int i = 0; i < arr_length; i++)
        {
            one = 0;
            zero = 0; 
            for(int j = 0; j < strs[i].length(); j++)
            {
                one += (strs[i][j] == '1');
                zero += (strs[i][j] == '0');
            }
            for(int j = m; j >= zero; j--)
            {
                for(int k = n; k >= one; k--)
                {
                    dp[j][k] = max(dp[j][k], 1 + dp[j-zero][k-one]);
                    res = max(res,dp[j][k]);
                }   
            }
        }    
        return res;
    }
};
