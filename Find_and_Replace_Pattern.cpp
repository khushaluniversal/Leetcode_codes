/*
Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
Example 2:

Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
 

Constraints:

1 <= pattern.length <= 20
1 <= words.length <= 50
words[i].length == pattern.length
pattern and words[i] are lowercase English letters.

*/

class Solution {
public:
    bool match(string word, string pattern)
    {
        unordered_map<char,char> w;
        unordered_map<char,char> p;
        
        if(word.length() != pattern.length())
            return false;
        
        for(int i = 0; i < word.length(); i++)
        {
            char m1 = word[i];
            char m2 = pattern[i];
            
            if(w.find(m1) == w.end())
                w[m1] = m2;
            
            if(p.find(m2) == p.end())
                p[m2] = m1;
            
            
            if(w[m1] != m2 || p[m2] != m1)
                return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int p_size = pattern.size();
        if(p_size == 1)
            return words;
        
        vector<string> result;
        
        for(string word:words)
        {
            if(match(word,pattern))
                result.push_back(word);
        }
        return result;
        
    }
};
