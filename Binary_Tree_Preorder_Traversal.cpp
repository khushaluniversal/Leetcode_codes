/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
        void preorderTraversal_util(TreeNode* root,vector<int> &res)
        {
            if(root == NULL)
                return;
            
            res.push_back(root->val);
            preorderTraversal_util(root->left,res);
            preorderTraversal_util(root->right,res);
            
        }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        
        preorderTraversal_util(root,res);
        return res;
    }
};
