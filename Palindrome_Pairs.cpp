/*
Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list, so that the concatenation of the two words words[i] + words[j] is a palindrome.

 

Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
Example 2:

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
Example 3:

Input: words = ["a",""]
Output: [[0,1],[1,0]]
 

Constraints:

1 <= words.length <= 5000
0 <= words[i].length <= 300
words[i] consists of lower-case English letters.
*/

class Solution {
public:
    bool isPalindrome(string a)
    {
        string b = string(a.rbegin(), a.rend()) ;
        if(a.compare(b) == 0)
            return true;
        
        return false;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> res;
        map<string,int> mp;
        
        map<string, int>::iterator it;
            
        if(n <= 0)
            return res;
        
        for(int i = 0; i < n; i++)
            mp.insert({words[i],i});
        
        it = mp.find("");
        
        //if words contain blank string 
        if( it != mp.end())
        {
            int blank_idx = it->second;
            
            for(int i = 0; i < n; i++)
            {
                
                if((i != blank_idx) && (isPalindrome(words[i])))
                {
                    res.push_back({i,blank_idx});
                    res.push_back({blank_idx,i});
                }
            }
        }
        
        //if string contains reverse of string
        for(int i = 0; i < n; i++)
        {
            string word = words[i];
            string rev_word = string(word.rbegin(),word.rend());
            it = mp.find(rev_word);
            if((it != mp.end()) && (it->second != i))
            {
                res.push_back({i,it->second});
            }
        }
        
        /*
        checking substrings present
        divide string into two half and check if left and right substring is palindrome
        for ex :
        i) for left half
            aabc and cba
            o/p : cbaaabc --> palindrome
        
        a |abc  --  cba
        
        ii) for right half
        dbacck and kcca  
        o/p: kcca dbacck
        
        db acck  -- kcca
        */
        for(int i = 0; i < n; i++)
        {
            string curr = words[i];
            for(int cut = 1; cut < curr.length(); cut++)
            {
                string left = curr.substr(0,cut);
                string right = curr.substr(cut);
                
                if(isPalindrome(left))
                {
                    string rev_right = string(right.rbegin(),right.rend());
                    it = mp.find(rev_right);
                    if(it != mp.end())
                    {
                        res.push_back({it->second,i});
                    }
                }
                if(isPalindrome(right))
                {
                    string rev_left = string(left.rbegin(),left.rend());
                    it = mp.find(rev_left);
                    if(it != mp.end())
                    {
                        res.push_back({i,it->second});
                    }
                }
                
            }
        }
        return res;
    }
};
