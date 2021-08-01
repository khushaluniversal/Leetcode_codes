/*
You are given two strings order and s. All the words of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

 

Example 1:

Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
Example 2:

Input: order = "cbafg", s = "abcd"
Output: "cbad"
 

Constraints:

1 <= order.length <= 26
1 <= s.length <= 200
order and s consist of lowercase English letters.
All the characters of order are unique.
*/

class Solution {
public:
    string customSortString(string order, string s) {
        int freq[26] = {0};
        bool visited[26] = {false};
        
        //find frequency of characters of string s
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i]-'a']++;
            visited[s[i]-'a'] = true;
        }
        s="";
        //now add chars of string order to resultant string
        for(int i = 0; i < order.length(); i++)
        {
            if(freq[order[i]-'a'])
            {
                while(freq[order[i]-'a'])
                {
                    s+=order[i];
                    visited[order[i]-'a'] = false;
                    freq[order[i]-'a']--;
                }
            }
        }
        //add remaining chars of string s
        for(int i = 0; i < 26; i++)
        {
            if(freq[i])
            {
                while(freq[i]){
                    s+= ('a'+i);
                    freq[i]--;
                }
                    
            }
        }
        return s;
        
    }
};
