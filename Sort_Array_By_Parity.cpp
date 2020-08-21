/*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.size() < 2)
            return A;
        
        int n = A.size();
        int l = 0;
        int r = n - 1;
        
        while(l < r)
        {
            //skipping all even elements at starting and stop if odd elements encounter
            while(l < n) 
            {
                if(A[l] & 1)
                    break;
                l++;
            }
            //if l reaches to end or right meaning there is no odd elements left
            if(l >= r)
                return A;
            
            //similar for right if there is even element encounter then stop
            while(r >= 0)
            {
                if(!(A[r] & 1))
                    break;
                r--;
            }
            //if right reaches to left end
            if(r <= l)
                return A;
            
            //swap left and right elements
            swap(A[l],A[r]);
            l++;
            r--;        
        }
        return A;
    }
};
