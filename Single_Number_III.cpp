/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(2,0);
        int res = 0;
        
        /*
        find the numbers which repeated once 
        after this step we will have resultant number which is XOR of all 
        non-repeated numbers
        */
        for(int i = 0;i < n; i++)
            res ^= nums[i];
        
        /*
        finding first non-matching bit from right as this will be easy to 
        separte it out two numbers 
        */
        int right_set_bit = res & ~(res-1);
        
        //separting numbers based on rightmost set bit
        for(int i = 0;i < n; i++)
        {
            if(right_set_bit & nums[i])
                v[0] ^= nums[i];
            
            else
                v[1] ^= nums[i];
        }
        return v;
    }
};
