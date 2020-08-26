/*
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n,"");
        
        for(int i = 1; i <= n; i++)
        {
            string temp = "";
            if((i%3) && (i % 5))
            {
                temp +=to_string(i);
                res[i-1] = temp;
                continue;
            }
            if(!(i % 3))
            {
                temp +="Fizz";
                res[i-1] = temp;
            }
            if(!(i % 5))
            {
                temp +="Buzz";
                res[i-1] = temp;
            }
           
            
        }
        return res;
        
        
    }
};
