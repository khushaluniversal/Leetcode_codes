/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
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
    int height(TreeNode* root)
    {
        if(root == NULL)
            return -1;
        else
        {
            int lheight = height(root->left);
            int rheight = height(root->right);
            return 1+max(lheight,rheight);
        }
        
    }
    void level_traverse(TreeNode *root,double *sum,int hi)
    {
       if(root == NULL)
           return;
        
        sum[hi] += root->val;
        level_traverse(root->left,sum,hi+1);
        level_traverse(root->right,sum,hi+1);
        
    }
    int get_node_count(TreeNode *root,int curr_lvl,int des_lvl)
    {
        if(curr_lvl == des_lvl)
            return 1;
        
        int left=0,right=0;
        if(root->left)
            left = get_node_count(root->left,curr_lvl+1,des_lvl);
        
        if(root->right)
            right = get_node_count(root->right,curr_lvl+1,des_lvl);
         
        return (left+right);
         
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root == NULL)
            return res;
        
        int h = height(root);
        double *sum = new double[h+1]();
        level_traverse(root,sum,0);
        /*
        for(int i = 0; i <= h; i++)
            cout<<sum[i]<<" ";
        
        cout<<endl;
        */
        int *node_count = new int[h+1]();
        
        for(int i = 0; i <= h; i++)
            node_count[i] = get_node_count(root,0,i);
    
        /*
         for(int i = 0; i <= h; i++)
            cout<<node_count[i]<<" ";
        
        cout<<endl;
        */
        for(int i = 0; i <= h; i++)
        {
            res.push_back(sum[i] / node_count[i]);
        }
        return res;
    }
};
