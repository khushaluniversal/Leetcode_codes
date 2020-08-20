/*
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
 
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
 
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 

 

Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 

Notes:

S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.
*/

class Solution {
public:
    string toGoatLatin(string S) {
        if(S.length() == 0)
            return S;
        
        vector<string> aux;
        string app = "a";
        istringstream iss(S); //separating words from statement
        S = "";
        for(std::string word; iss >> word; )  
        {
            //for consonent, other than vowel
            if(!((word[0] == 'a') || (word[0] == 'e') || (word[0] == 'i') || (word[0] == 'o') || (word[0] == 'u') || (word[0] == 'A') || (word[0] == 'E') || (word[0] == 'I') || (word[0] == 'O') || (word[0] == 'U')))
            {
                char ch = word[0];
                word.erase(0,1);
                word += ch;
            }
            
            word.append("ma"); //append "ma" at end
            word.append(app); //append "a" depending on position
            app += 'a';
            S.append(word);  //append string to original
            S.append(" ");
        } 
        S.erase(S.size() - 1); //erase last space
        return S;
    }
};
