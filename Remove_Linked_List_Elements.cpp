/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

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
    ListNode* removeElements(ListNode* head, int val) {
        //pointers for deletion
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr != NULL)
        {
            if(curr->val == val)
            {
                //if node to be deleted is head node
                if(prev == NULL)
                    head = head->next;
                
                //other than head node
                else
                    prev->next = curr->next;
                
            }
            else
                prev = curr;
            
            
            curr = curr->next?curr->next:NULL;
        }
        return head;
    }
};
