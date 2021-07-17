/*
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

 

Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
*/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int num1_len = nums1.size();
        int num2_len = nums2.size();
        
        //if any of the array is of size 0 then no common element
        if((num1_len == 0) || (num2_len == 0))
            return 0;
        
        //creating dp array
        int **dp = new int*[num1_len+1];
        
        for(int i = 0; i <= num1_len; i++)
            dp[i] = new int[num2_len+1];
        
        for(int i = 0; i <= num1_len; i++)
            for(int j = 0; j <= num2_len; j++)
                dp[i][j] = 0;
        
        int ans = 0;
        /*
            for each subarray we are updating dp array and finding max of it
            the max value is length of common subarray
         */
            
        for(int i = 1; i <= num1_len; i++)
        {
            for(int j = 1; j <= num2_len;j++)
            {
                if(nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                    
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        /*
        for(int i = 0; i <= num1_len; i++) 
        {
            for(int j = 0; j <= num2_len; j++)
                cout<<dp[i][j]<<" ";
            
            cout<<endl;
        }
        */
        return ans;
    }
};
