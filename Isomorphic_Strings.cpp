/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        
        //if lengths are different then not isomorphic
        if(s_len != t_len)
            return false;
        
        map<char,char> umap;
        //array to check char is already appeared in target string
        char appeared[256] = {false}; 
        
        for(int i = 0; i < s_len; i++)
        {
            //if char is not present in map or first time appeared
            if(umap.find(s[i]) == umap.end())
            {
                //if it's already appeared in target string then 1 on 1 mapping not possible
                if(appeared[t[i]])
                    return false;
                
                //marking char of target string visited 
                appeared[t[i]] = true;
                
                //adding to map
                umap[s[i]] = t[i];
                    
            }
            //if mapping of source char and char from target string is not equal then not isomorphic
            else if(umap[s[i]] != t[i])
                    return false;
            
        }
        return true;
        
    }
};
