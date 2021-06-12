/*
Alice and Bob take turns playing a game, with Alice starting first.

There are n stones arranged in a row. On each player's turn, they can remove either the leftmost stone or the rightmost stone from the row and receive points equal to the sum of the remaining stones' values in the row. The winner is the one with the higher score when there are no stones left to remove.

Bob found that he will always lose this game (poor Bob, he always loses), so he decided to minimize the score's difference. Alice's goal is to maximize the difference in the score.

Given an array of integers stones where stones[i] represents the value of the ith stone from the left, return the difference in Alice and Bob's score if they both play optimally.

 

Example 1:

Input: stones = [5,3,1,4,2]
Output: 6
Explanation: 
- Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, stones = [5,3,1,4].
- Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, stones = [3,1,4].
- Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, stones = [1,4].
- Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
- Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
The score difference is 18 - 12 = 6.
Example 2:

Input: stones = [7,90,5,1,100,10,10,2]
Output: 122
 

Constraints:

n == stones.length
2 <= n <= 1000
1 <= stones[i] <= 1000
*/

class Solution {
public:
    
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        
        int *dp = new int[n]();
        /*
        stones          score
        
        A                  0
        AB                 max(A,B)
        ABC         i) If Alice select A
                        then Alice score = B+C and Bob's score = max(B,C)
                        score difference = B+C-max(B,C)
                    ii) If Alice select C
                        then Alice score = A+B and Bob's score = max(A,B)
                    score difference = A+B-max(A,B)
                    
        ABCD        i) If Alice select A
                        then Alice score = B+C+D and Bob's score = max(B,C,D)
                        score difference = B+C+D-max(B,C,D)
                    ii) If Alice select C
                        then Alice score = A+B+C and Bob's score = max(A,B,C)
                    score difference = A+B+C-max(A,B,C)
        */
        for(int i = n-1; i >= 0; i--)
        {
            int temp = 0;
            int sum = stones[i];
            
            for(int j = i; j < n; j++)
            {
                if(i != j)
                {
                    sum += stones[j];
                    int a = sum - stones[j];
                    int b = sum - stones[i];
                    dp[j] = max(a-temp, b-dp[j]);
                    
                }
                temp = dp[j];
            }
        }
        return dp[n-1];
        
    }        
};
