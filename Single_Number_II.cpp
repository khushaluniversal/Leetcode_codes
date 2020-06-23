/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

class Solution {
public:
    /*
    find bits appeared for 1,4,7.... number and stored in one_time
    find bits appeared for 2,5,8...  number and store it in sec_time
    finally return value of one_time.
    */
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        
        if(n <= 2)
            return nums[0];
        
        int one_time= 0;
        int sec_time = 0;
        int common = 0;
        for(int i = 0; i < n; i++)
        {
            //finding 
            sec_time |= (one_time & nums[i]);
            
            one_time = one_time ^ nums[i];
            
            common = ~(one_time & sec_time);
            
            one_time = one_time & common;
            sec_time = sec_time & common;
        }
        return one_time;
    }
};
