/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*> Q;
        Q.push(root);
        int level = 1;
        
        /*
        performing level order traversal and at every level we are 
        reversing the all elements of level if it's previous is not reversed
        to achieve zigzag traversal
        */
        while(!Q.empty())
        {
            int qsize = Q.size();
            vector<int> aux;
            while(qsize)
            {
                TreeNode* temp = Q.front();
                Q.pop();
                aux.push_back(temp->val);
                
                if(temp->left)
                    Q.push(temp->left);
                    
                if(temp->right)
                    Q.push(temp->right);
                
                qsize--;
            }
            if(level & 1)
                res.push_back(aux);
            else
            {
                reverse(aux.begin(),aux.end());
                res.push_back(aux);
            }
            level++;
        }
        return res;
        
    }
};
