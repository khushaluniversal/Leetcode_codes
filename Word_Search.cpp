/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

*/

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, int count, string word)
    {
        //base case as we got all chars of string
        if(count == word.size())
            return true;
        
        //we are crossing border or current letter is not matching then return false
        if((i < 0) || (i >= board.size()) || (j < 0) || (j >= board[0].size()) || (board[i][j] != word[count]))
           return false;
           
        //we are saving original letter as no need to visit same letter again
        char temp = board[i][j];
        board[i][j] = '#';
        //searching in all four direction
        bool found = dfs(board,i-1,j,count+1,word)
                    || dfs(board,i+1,j,count+1,word)
                    || dfs(board,i,j-1,count+1,word)
                    || dfs(board,i,j+1,count+1,word);
        
        //retrieve original letter
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        /*checking each character of board and if it matches with
            starting letter of word we apply DFS and search remaining character
        */
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((board[i][j] == word[0]) && dfs(board,i,j,0,word))
                    return true;
            }
        }
        //word not found
        return false;
    }
};
