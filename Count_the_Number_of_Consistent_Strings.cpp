/*
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

 

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 

Constraints:

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.
*/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int arr[26] = {0};
        int res = 0;
        //count frequencies of character of allowed and compare
        //with every word in words 
        for(int i = 0; i < allowed.length(); i++)
            arr[allowed[i]-'a']++;
        
        for(int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            int w_len = word.length();
            int j = 0;
            for(j = 0; j < w_len; j++)
            {
                if(!arr[word[j]-'a'])
                    break;
            }
            if(j == w_len)
                res++;
        }
        return res;
    }
};
