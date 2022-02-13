/*
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

 

Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 105
 

Note: This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
    void inorder_traversal(TreeNode *root,vector<int> &traversal)
    {
        if(root==NULL)
            return;
        
        inorder_traversal(root->left,traversal);
        traversal.push_back(root->val);
        inorder_traversal(root->right,traversal);
            
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> traversal;
        
        inorder_traversal(root,traversal);
        
        int min_diff=INT_MAX;
        
        for(unsigned int i = 0; i < traversal.size()-1; ++i)
        {
            min_diff = min(min_diff,traversal[i+1] - traversal[i]);
            
        }
        return min_diff;       
    }
};
