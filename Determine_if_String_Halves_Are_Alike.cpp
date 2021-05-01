/*
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

 

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
Example 3:

Input: s = "MerryChristmas"
Output: false
Example 4:

Input: s = "AbCdEfGh"
Output: true
 

Constraints:

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.
*/

class Solution {
public:
    bool isvowel(char x)
    {
        if (x == 'a' || x == 'e' || x == 'i' ||
            x == 'o' || x == 'u' || x == 'A' ||
            x == 'E' || x == 'I' || x == 'O' || x == 'U')
            return true;
        
        return false;
    }
    bool halvesAreAlike(string s) {
        int s_length = s.length();
        
        if(s_length < 2)
            return false;
        
        int start = 0;
        int mid = start + (s_length / 2);
        
        int count_lh = 0;
        int count_uh = 0;
        
        
        while(start < (s_length / 2))
        {
            if(isvowel(s[start]))
                count_lh++;
            
            if(isvowel(s[mid]))
                count_uh++;
               
            start++;
            mid++;
        }
        return count_lh == count_uh;
        
    }
};
