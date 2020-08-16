/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0)
            return 0;
        
        if(n == 1)
            return nums[0];
        
        int l = 0;
        int r = n - 1;
        
        while(l < r)
        {
            int m = l + (r - l) / 2;
            
            if(nums[m+1] < nums[m])
                return nums[m+1];
            
            else if(nums[m] < nums[r])
                r = m;
            else
                l = m+1;
        }
        return nums[l];
    }
};
