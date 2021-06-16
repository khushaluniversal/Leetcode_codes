/*
You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

 Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
 

Constraints:

1 <= matchsticks.length <= 15
0 <= matchsticks[i] <= 109
*/

class Solution {
public:
    bool makesquareHelper(vector<int>& matchsticks, int i, int *side)
    {
        /*
            if we reach end of vector and check each side is 0 
            or not. If side is not 0 then return false
        */
        if(i == matchsticks.size())
        {
            return((side[0] == 0) && (side[1] == 0) && (side[2] == 0) && (side[3] == 0));
        }
        
        /*
            backtracking logic:
            go to each each side and substract matchsticks length and recurse with next matchsticks
            once it retuns 0 then it will form side
        */
        for(int j = 0; j < 4; j++)
        {
            if(matchsticks[i] > side[j]) continue;
            
            side[j] -= matchsticks[i];
            
            if(makesquareHelper(matchsticks,i+1,side)) return true;
            
            side[j] += matchsticks[i];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int N = matchsticks.size(); 
        
        //Less than 4 sides available then return false
        if(N < 4)
            return false;
        
        //find perimeter of square so side = perimeter/4
        int perimeter = 0;
        perimeter = accumulate(matchsticks.begin(),matchsticks.end(),0);
        
        //if perimeter is not divisible by 4 then it's cannot create square
        if((perimeter % 4) != 0)
            return false;
        
        //create side array with perimeter/4 side
        int *side = new int[4];
        
        for(int i = 0; i < 4; i++)
            side[i] = perimeter/4;
        
        //sort in descending order
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        return makesquareHelper(matchsticks,0,side);
    }
};
