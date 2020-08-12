/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
Note that the row index starts from 0.
Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        
        long long int C = 1;
        for(int i = 1; i <= (1+rowIndex); i++)
        {
            res.push_back(C);
            
            C = C * (rowIndex + 1 - i) / i;
        }
        
        return res;
            
    }
};
