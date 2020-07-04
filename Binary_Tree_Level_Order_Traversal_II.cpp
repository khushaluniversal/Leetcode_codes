/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
/*
class Solution {
public:
    int find_level(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int lheight = find_level(root->left);
        int rheight = find_level(root->right);
        
        return 1 + max(lheight,rheight);
        
    }
    void add_level(TreeNode* root, int level, vector<int> &temp, int curr_level)
    {
        if(root == NULL)
            return;
        
        if(curr_level == level)
            temp.push_back(root->val);
        
        curr_level++;
        add_level(root->left,level,temp,curr_level);
        add_level(root->right,level,temp,curr_level);
        
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int l = find_level(root);   
        vector<vector<int>> res;
        
        for(int i = l; i > 0; i--)
        {
            vector<int> temp;
            add_level(root,i,temp,1);
            res.push_back(temp);
        }
        return res;
    }
};
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
   
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
           
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*> Q;
        
        Q.push(root);
        
        while(!Q.empty())
        {
            int node_count = Q.size();
            vector<int> aug;           
            while(node_count > 0)
            {
                
                TreeNode* temp = Q.front();
                Q.pop();
                aug.push_back(temp->val);
                if(temp->left)
                    Q.push(temp->left);
            
                if(temp->right)
                    Q.push(temp->right);
                
                node_count--;
            }
            res.push_back(aug);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
