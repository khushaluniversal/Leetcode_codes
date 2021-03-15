/*
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
Example 3:

Input: head = [1], k = 1
Output: [1]
Example 4:

Input: head = [1,2], k = 1
Output: [2,1]
Example 5:

Input: head = [1,2,3], k = 2
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100
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
class Solution {
public:
    int count_nodes(ListNode* head)
    {
        int n = 0;
        ListNode* temp = head;
        
        while(temp != NULL)
        {
            n++;
            temp = temp->next;
        }
        return n;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        
        if(head == NULL)
            return head;
        
        //counting number of nodes in linked list
        int n = count_nodes(head);
        
        //if number of nodes are less than k then return
        if(n < k)
            return head;
        
        //if nodes are same from front and back are same then no swapping.
        if ((2 * k - 1) == n) 
            return head;
        
        //find kth node from fron and keep track of previous node also for swapping
        ListNode* x = head;
        ListNode* x_prev = NULL;
        
        for(int i = 1; i < k; i++)
        {
            x_prev = x;
            x = x->next;
        }
        
        //find (n-k+1)th node from front and keep track of previous node also for swapping
        ListNode* y = head;
        ListNode* y_prev = NULL;
        
        for(int i = 1; i < (n-k+1); i++)
        {
            y_prev = y;
            y = y->next;
        }
        
        //if previous node of x is not NULL then point next of it to y
        if(x_prev)
            x_prev->next = y;
        
        //if previous node of y is not NULL then point next of it to x
        if(y_prev)
            y_prev->next = x;
        
        //swap nodes 
        ListNode* temp = x->next;
        x->next = y->next;
        y->next = temp;
        
        //if it's head node then we need to change for k==1
        if(k == 1)
            head = y;
        
        //if it's last node then we need to make it as head;
        if(k == n)
            head = x;
        
        return head;
        
    }
};
