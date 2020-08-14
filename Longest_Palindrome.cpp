/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

*/

class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        
        if(n < 2)
            return n;
        
        map<char,int> mp;
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                mp.erase(s[i]);
                count++;
            }
            else
                mp[s[i]] = 1;
        }
        if(!mp.size())
            return (2 * count);
        
        return((2 * count) + 1);
    }
};
