/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        
        int dig_len = digits.length();
        
        if(dig_len <= 0)
            return res;
        
        string table[10] = {"0","1","abc",
                          "def","ghi","jkl",
                          "mno","pqrs","tuv",
                          "wxyz"};
        
        queue<string> q;
        q.push("");
        
        while(!q.empty())
        {
            string s = q.front();
            q.pop();
            
            if(s.length() == dig_len)
                res.push_back(s);
            else
            {
                for(char letter:table[digits[s.length()]-'0'])
                    q.push(s+letter);
            }
        }
        return res;
    }
};
