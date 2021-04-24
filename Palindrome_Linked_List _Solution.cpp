/*
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
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
    void reverse_list(ListNode** head)
    {
        if((*head == NULL) || ((*head)->next == NULL))
            return;
        
        ListNode* prev = NULL;
        ListNode* curr = *head;
        ListNode* next = *head;
        
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
        }
        *head = prev;
    }
    bool compare_list(ListNode* head1, ListNode* head2)
    {
        while(head1 && head2)
        {
            if(head1->val != head2->val)
               return false;
            
            head1 = head1->next;
            head2 = head2->next;
        }
        if(head1 || head2)
            return false;
        
        return true;

    }
    bool isPalindrome(ListNode* head) {
        if((head == NULL) || (head->next == NULL))
            return true;
        
        ListNode *slow_ptr = head;
        ListNode *fast_ptr = head;
        ListNode *second_half = NULL;
        ListNode *prev_of_first_list = head;
        while(fast_ptr && fast_ptr->next)
        {
            fast_ptr = fast_ptr->next->next;
            prev_of_first_list = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        ListNode *middle_node = NULL;
        
        //for odd number of nodes in LL
        if(fast_ptr != NULL)
        {
            middle_node = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        second_half = slow_ptr;
        prev_of_first_list->next = NULL;
        
        reverse_list(&second_half);
       
        bool cmp_lst = true;
        cmp_lst = compare_list(head,second_half);
        reverse_list(&second_half);
        if(middle_node)
        {
            prev_of_first_list->next = middle_node;
            middle_node->next = second_half;
        }
        else
            prev_of_first_list->next = second_half;  
        
        return cmp_lst;
        
    }
};
