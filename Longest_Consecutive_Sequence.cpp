/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        if(n <= 1)
            return n;
        
        set<int> s;
        
        
        
        for(int i = 0; i < n; i++)
            s.insert(nums[i]);
        
        vector<int> v(s.begin(),s.end());
        int res = 0;
        int d = 1;
       
        for(int i = 0; i < v.size()-1; i++)
        {
            
            if((v[i+1] - v[i]) == 1)
                d++;
            else
            {
                res = max(res,d);
                d = 1;
            }
            
        }
        return max(res,d);
    }
};
