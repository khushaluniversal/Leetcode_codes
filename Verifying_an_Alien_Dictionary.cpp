/*
In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.
*/

class Solution {
public:
    bool isBigger(string s1, string s2,char *table)
    {
        for(int j = 0; j < min(s1.length(),s2.length()); j++)
        {
            if(s1[j] != s2[j])
                return table[s1[j]-'a'] > table[s2[j]-'a'];
                    
        }   
        return s1.length() > s2.length();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int words_len = words.size();
        
        if(words_len <= 0)
            return true;
        
        char *table = new char[26];
            
        for(int i = 0; i < order.length(); i++)
            table[order[i]-'a'] = i;
        
        
        for(int i = 0;i < words_len-1; i++)
        {
            
            if(isBigger(words[i],words[i+1],table))
                return false;
            
        }
        return true;    
        
    }
};
