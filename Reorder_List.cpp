/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

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
    void reorderList(ListNode* head) {
        if((head == NULL) || (head->next == NULL))
            return;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        //divide list into two halves
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //list1
        ListNode* head1 = head;
        
        //list2
        ListNode* head2 = slow->next;
        slow->next = NULL;
        
        //reverse list2 
        ListNode* current = head2;
        ListNode* prev = NULL;
        ListNode* next = head2;
        
        while(current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head2 = prev;
        current = NULL;
        //create dummy node and mark it as head
        
        head = new ListNode(0);
        current = head;
        //attach node of list1 first and then node of list2
        while(head1 || head2)
        {
            if(head1)
            {
                current->next = head1;
                current  = current->next;
                head1 = head1->next;
            }
            if(head2)
            {
                current->next = head2;
                current  = current->next;
                head2 = head2->next;
            }
        }
        //adjust resultant head of list
        head = head->next;
    }
};
