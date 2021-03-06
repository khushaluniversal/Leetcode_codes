/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

class Solution {
public:
    int find_start(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int index = -1;
        
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] >= target)
                end = mid - 1;
            else
                start = mid + 1;
            
            if(nums[mid] == target)
                index = mid;
        }
        return index;
    }
    int find_end(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int index = -1;
        
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] <= target)
                start = mid + 1;
            else
                end = mid - 1;
            
            if(nums[mid] == target)
                index = mid;
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int num_length = nums.size();
        vector<int> res{-1,-1};
        
        if(num_length == 0)
            return res;
        
        
        int start = 0;
        int end = num_length - 1;
        
        res[0] = find_start(nums,target);
        res[1] = find_end(nums,target);
        return res;
    }
};
