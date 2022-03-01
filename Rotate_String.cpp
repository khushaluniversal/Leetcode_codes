/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
 

Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        
        for(int i = 1; i < n; ++i)
        {
            /*
            take substring n-k and k length substrings and reverse them
            so that we can get rotated array.This we will match with 'goal' string
            */
            string sb1 = s.substr(n-i,n);
            string sb2 = s.substr(0,n-i);
            
            reverse(sb1.begin(),sb1.end());
            reverse(sb2.begin(),sb2.end());
            string t = sb2+sb1;
            reverse(t.begin(),t.end());
            //cout<<sb1<<endl;
            //cout<<sb2<<endl;
            //cout<<t<<endl;
            if(goal.compare(t) == 0)
                return true;
        }
        return false;
        
    }
};
