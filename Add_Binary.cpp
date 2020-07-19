/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.length();
        int len_b = b.length();
        
        int i = len_a - 1;
        int j = len_b - 1;
        string res = "";
        int carry = 0,sum=0;
        while((i >= 0) || (j >= 0))
        {
            //taking char of string a starting from right
            sum = (i >= 0) ? (char(a[i]) - '0') : 0;
            
            //taking char of string b starting from right
            sum += ((j >= 0) ? (char(b[j]) - '0') : 0);
            
            //taking carry
            sum += carry;
            
            //finding carry
            carry = sum / 2;
            
            //finding resultant sum
            sum = sum % 2;
            
            //add to resultant string
            res += (char(sum) + '0');
            i--;
            j--;
        }
        //if carry generated any then add to string
        if(carry)
            res += '1';
        
        //reverese resultant string 
        reverse(res.begin(),res.end());
        return res;
    }
};
