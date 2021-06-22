/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30
*/

class Solution {
public:
    vector<int> getRow(int numRow)
    {
        vector<int> row;
        long long int C = 1;
        
        /*
            each row of pascal triangle contain (1+row_index) elements
            each element is generated using formula
            C = C * (numRow + 1 - i) / i;
        */
        for(int i = 1; i <= (1 + numRow); i++)
        {
            row.push_back(C);
            C = C * (numRow + 1 - i) / i;
        }
        return row;
    }
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;
        //generate pascal row
        for(int i = 0; i < numRows; i++)
        {
            vector<int> aux;
            aux = getRow(i);
            res.push_back(aux);
        }
        return res;
    }
};
