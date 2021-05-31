/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 

Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/

class Solution {
public:
    int string_to_int(string s)
    {
        stringstream ss(s);
        int x = 0;
	    ss >> x;
        return x;
    }
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        
        stack<int> opnd;
        string oper = "+-*/";
        int n = tokens.size();
        
        for(int i = 0; i < n; i++)
        {
            size_t found = oper.find(tokens[i]);

            if(found == string::npos)
            {
                opnd.push(string_to_int(tokens[i]));
                continue;
            }
            else
            {
                int val1 = opnd.top();
                opnd.pop();
                int val2 = opnd.top();
                opnd.pop();
                
                switch(found)
                {
                    case 0 :
                        opnd.push(val1 + val2);
                        break;
                
                    case 1 :
                        opnd.push(val2 - val1);
                        break;
                
                    case 2 :
                        opnd.push(val1 * val2);
                        break;
                
                    default:
                        opnd.push(val2 / val1);
                        break;
                
                }
                
            }
            
        }
        res = opnd.top();
        opnd.pop();
        return res;    
        
    }
};
