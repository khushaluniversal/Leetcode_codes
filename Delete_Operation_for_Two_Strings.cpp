/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
*/

class Solution {
public:
    //finding LCS between two strings
    int find_lcs(string word1, string word2, int m, int n)
    {
        int LCS[m+1][n+1];
        
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0;j <= n; j++)
            {
                if((i == 0) || (j == 0))
                    LCS[i][j] = 0;
                
                else if(word1[i-1] == word2[j-1])
                    LCS[i][j] = 1 + LCS[i-1][j-1];
                
                else
                    LCS[i][j] = max(LCS[i][j-1],LCS[i-1][j]);
            }
        }
        return LCS[m][n];
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        int lcs = find_lcs(word1,word2,m,n);
        //final distance would be subtracting LCS from individual string
        return(m - lcs + n-lcs);
    }
};
