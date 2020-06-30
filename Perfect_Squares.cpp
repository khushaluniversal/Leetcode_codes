/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.

Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

class Solution {
public:
    int numSquares(int n) {
        int *dp = new int[n+1];
        for(int i = 0; i <= n; i++)
            dp[i] = INT_MAX;
        
        int sqrt_n =(int)sqrt(n);
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= sqrt_n; j++)
            {
                if(i == (j * j))
                    dp[i] = 1;
                
                else if(i > (j * j))
                    dp[i] = min(dp[i], 1 + dp[i-(j*j)]);
                    
            }
        }   
        return dp[n];
    }
};
