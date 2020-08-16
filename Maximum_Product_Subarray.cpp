/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        if(n == 1)
            return nums[0];
        
        int prod = nums[0];
        int max_val = nums[0];
        int min_val = nums[0];
        /*
        if any negative number comes in array then swap the max and min val.
        */
        for(int i = 1; i < n; i++)
        {
            if(nums[i] < 0)
                swap(min_val,max_val);
            
            max_val = max(nums[i], max_val*nums[i]);
            min_val = min(nums[i], min_val*nums[i]);
            
            prod = max(prod,max_val);
            
        }
        return prod;
    }
};
