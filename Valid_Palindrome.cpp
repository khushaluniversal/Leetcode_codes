/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if(n == 0)
            return true;
        
        int l = 0;
        int r = n-1;
        
        while(l < r)
        {
            if(!isalnum(s[l]))
            {
                l++;
                continue;
            }
            else if(!isalnum(s[r]))
            {
                r--;
                continue;
            }
            else
            {       
                //if(isdigit(s[l]) && isdigit(s[r]))
                  //  if(s[l] != s[r])
                    //    return false;
                
                //else if(isalpha(s[l]) && isalpha(s[r]))
                    if(tolower(s[l]) != tolower(s[r]))
                        return false;
                
                //else
                  //  return false;
                
                l++;
                r--;
            }
                
        }
        return true;
        
    }
};
