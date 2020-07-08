/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
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
    void pathSum_util(TreeNode* root, int sum, vector<vector<int>> &res,vector<int> temp)
    {
        if(root == NULL)
            return;
        
        temp.push_back(root->val);
        if((root->left == NULL) && (root->right == NULL) && (sum == root->val))
        {
            res.push_back(temp);
            return;
        }
        
        pathSum_util(root->left,sum-root->val,res,temp);
        pathSum_util(root->right,sum-root->val,res,temp);
        
        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
       vector<vector<int>> res;
        
        if(root == NULL)
            return res;
        
        vector<int> temp;
        
        pathSum_util(root,sum,res,temp);
        return res;
        
    }
};
