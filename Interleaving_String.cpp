/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        
        bool dp[m+1][n+1];
        
        memset(dp,false,sizeof(dp));
        
        if((m+n) != s3.length())
            return false;
        
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                //if both s1 and s2 is empty
                if((i == 0) && (j == 0))
                   dp[i][j] = true;
                
                //if s1 is empty
                else if(i == 0)
                {
                    if(s2[j-1] == s3[j-1])
                    dp[i][j] = dp[i][j-1];
                }
                //if s2 is empty
                else if(j == 0)
                {
                    if(s1[i-1] == s3[i-1])
                    dp[i][j] = dp[i-1][j];
                }
                //if current character of s3 matches with s1 but not with s2 
                else if((s1[i-1] == s3[i+j-1]) && (s2[j-1] != s3[i+j-1]))
                    dp[i][j] = dp[i-1][j];
                
                //if current character of s3 matches with s2 but not with s1 
                else if((s2[j-1] == s3[i+j-1]) && (s1[i-1] != s3[i+j-1]))
                    dp[i][j] = dp[i][j-1];
                
                //if current character of s3 matches with s1 and s2 then 
                else if((s2[j-1] == s3[i+j-1]) && (s1[i-1] == s3[i+j-1]))
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};
