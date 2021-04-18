/*
A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

 

Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
Example 2:

Input: sentence = "leetcode"
Output: false
 

Constraints:

1 <= sentence.length <= 1000
sentence consists of lowercase English letters.
*/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int *all_char = new int[26]();
        
        int s_size = sentence.size();
        
        for(int i = 0; i < s_size; i++)
            all_char[sentence[i]-'a']++;
        
        for(int i = 0; i < 26; i++)
        {
            if(all_char[i] == 0)
                return false;
        }
        return true;
    }
};
