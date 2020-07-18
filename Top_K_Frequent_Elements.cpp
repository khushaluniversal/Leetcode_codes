/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        vector<int> res;
        vector<pair<int,int>> vec;
        int n = nums.size();
        
        if(k > n)
            return res;
        
        for(int i = 0; i < n; i++)
        {
            if(umap.find(nums[i]) != umap.end())
                umap[nums[i]]++;
            
            else
                umap.insert({nums[i],1});
        }
        std::copy(umap.begin(),
			umap.end(),
			std::back_inserter<std::vector<pair<int,int>>>(vec));
        
        std::sort(vec.begin(), vec.end(),
			[](const pair<int,int> &l, const pair<int,int> &r) {
				if (l.second != r.second)
					return l.second > r.second;

				return l.first > r.first;
			});
        
        for (auto const &pair: vec)
        {
            res.push_back(pair.first);
            k--;
            if(!k)
                break;
        }
        
        return res;
    }
};
