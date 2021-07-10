/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104
*/

class Solution {
public:
    int find_crossover(vector<int>& arr, int l, int h,int x)
    {
        //return the index if element found
        if(arr[h] <= x)
            return h;
        
        if(arr[l] > x)
            return l;
        
        
        int mid = l + ((h-l) / 2);
        
        if((arr[mid] <= x) && (arr[mid+1] > x))
            return mid;
        
        if(arr[mid] < x)
            return find_crossover(arr,mid+1,h,x);
        
        return find_crossover(arr,l,mid-1,x);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        
        int n = arr.size();
        
        if(n < k)
            return res;
        
        int count = 0;
        
        int l = find_crossover(arr,0,n-1,x);
        
        //right index of crossover
        int r = l + 1;
        
        
        /*
            traverse left and right part of crossover point and add the resultant element in 
            vector only if it satisfies above criteria
        */
        while((l >= 0) && (r < n) && (count < k))
        {
            //insert at begin of vector as left elements are smaller  
            if((x - arr[l]) <= (arr[r] - x))
                res.insert(res.begin(),arr[l--]);
            
            else
                res.push_back(arr[r++]);
            
            count++;
        }
        //no more elements on right side
        while((count < k) && (l >= 0)) {
            res.insert(res.begin(),arr[l--]);
            count++;
        }
        //no more elements on left side
        while((count < k) && (r <  n)) {
            res.push_back(arr[r++]);
            count++;
        }
        return res;
    }
};
