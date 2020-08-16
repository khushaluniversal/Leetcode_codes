/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        if(n == 0)
            return 0;
        int *left = new int[n];
        int *right = new int[n];
        
        int profit = 0;
        left[0] = 0;
        int min_ele = prices[0];
        
        for(int i = 1; i < n; i++)
        {
            min_ele = min(min_ele,prices[i]);
            left[i] = max(prices[i]-min_ele,left[i-1]);
        }
        right[n-1] = 0;
        int max_ele = prices[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            max_ele = max(max_ele,prices[i]);
            right[i] = max(right[i+1], max_ele-prices[i]);
        }
        for(int i = 0; i < n; i++)
        {
            profit = max(profit, left[i]+right[i]);
        }
        
        
        return profit;
    }
};
