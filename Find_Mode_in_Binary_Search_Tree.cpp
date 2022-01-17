/*
Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [1,null,2,2]
Output: [2]
Example 2:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
 

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

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
    void dfs(TreeNode* root,vector<int> &eles)
    {
        if(root == NULL)
            return;
        
        eles.push_back(root->val);
        
        if(root->left)
            dfs(root->left,eles);
        
        if(root->right)
            dfs(root->right,eles);
        
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> umap;
        vector<int> eles;
        
        //using DFS to add elements to vector
        dfs(root,eles);
        
        //find frequenecy of elements
        //find max count of occurence
        int max_count = 0;
        for(auto n:eles)
        {
            if(umap.find(n) == umap.end())
                umap[n] = 1;
            
            else
                umap[n] += 1;
            
            max_count = max(max_count,umap[n]);
        }
        eles.clear();
        for(auto it=umap.begin(); it != umap.end(); ++it)
        {
            if(max_count == it->second)
                eles.push_back(it->first);
        }
        
        return eles;
        
    }
};
