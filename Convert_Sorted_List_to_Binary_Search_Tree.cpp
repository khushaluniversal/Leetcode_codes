/*
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

 

Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [0]
Output: [0]
Example 4:

Input: head = [1,3]
Output: [3,1]
 

Constraints:

The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    int countNodes(ListNode* head)
    {
        int count = 0;
        
        while(head != NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    }
    TreeNode* sortedListToBSTUtil(ListNode** head,int N)
    {
        //if there are no nodes then return NULL
        if(N <= 0)
            return NULL;
        
        //construct left subtree
        TreeNode* left = sortedListToBSTUtil(head,N/2);
        //construct root
        TreeNode* root = new TreeNode((*head)->val);
        //attach left subtree to root
        root->left = left;
        
        //Advance head to next in LL
        *head = (*head)->next;
        
        //construct right subtree
        root->right = sortedListToBSTUtil(head,(N-N/2-1));
        
        
        return root;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        int n = countNodes(head);
        
        return sortedListToBSTUtil(&head,n);
        
    }
};
