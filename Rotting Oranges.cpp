/*
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.
*/

class Solution {
public:
    bool delim(pair<int,int> temp)
    {
        return ((temp.first == -1) && (temp.second == -1));
    }
    bool isvalid(int x,int y, int m,int n)
    {
        return(x >= 0  && x < m && y >= 0  && y < n);
    }
    bool checkall(vector<vector<int>>& grid)
    {
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                    return true;
            }
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        
        int n = grid[0].size();
        queue<pair<int,int>> Q;
        pair<int,int> temp;
        int ans = 0;
        //finding position of all rotten oranges
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                {
                    temp.first = i;
                    temp.second = j;
                    Q.push(temp);
                }
            }
        }
        //adding delimiter
        temp.first = -1;
        temp.second = -1;
        Q.push(temp);
        
        while(!Q.empty())
        {
            bool flag = false; //flag to add time only once
            while(!delim(Q.front()))
            {
                temp = Q.front();  
                //checking all four adjacent oranges and if it's fresh then make it rotten
                if(isvalid(temp.first+1,temp.second,m,n) && (grid[temp.first+1][temp.second] == 1))
                {
                    if(!flag)
                    {
                        ans++;
                        flag = true;
                    }
                    temp.first++;
                    grid[temp.first][temp.second] = 2; //making rotten
                    Q.push(temp);
                    temp.first--;
                }
                if(isvalid(temp.first-1,temp.second,m,n) && (grid[temp.first-1][temp.second] == 1))
                {
                    if(!flag)
                    {
                        ans++;
                        flag = true;
                    }
                    temp.first--;
                    grid[temp.first][temp.second] = 2;
                    Q.push(temp);
                    temp.first++;
                }
                if(isvalid(temp.first,temp.second+1,m,n) && (grid[temp.first][temp.second+1] == 1))
                {
                    if(!flag)
                    {
                        ans++;
                        flag = true;
                    }
                    temp.second++;
                    grid[temp.first][temp.second] = 2;
                    
                    Q.push(temp);
                    temp.second--;
                }
                if(isvalid(temp.first,temp.second-1,m,n) && (grid[temp.first][temp.second-1] == 1))
                {
                    if(!flag)
                    {
                        ans++;
                        flag = true;
                    }
                    temp.second--;
                    grid[temp.first][temp.second] = 2;
                    Q.push(temp);
                }
                Q.pop();
            }
            Q.pop();
            //adding dellimiter
            if(!Q.empty())
            {
                temp.first = -1;
                temp.second = -1;
                Q.push(temp);
            }
        }
        return checkall(grid)?(-1):ans;
        
    }
};
