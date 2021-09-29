/*
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

 

Example 1:


Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
Example 2:


Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
 

Constraints:

The number of nodes in the list is in the range [0, 1000].
0 <= Node.val <= 1000
1 <= k <= 50
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
        if(head == NULL)
            return 0;
        
        ListNode *travel = head;
        int n = 0; 
        while(travel != NULL)
        {
            n++;
            travel = travel->next;
        }
        return n;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N = count_nodes(head);
        
        int parts = N / k;  //total number of equal parts
        int extra_parts = N % k; //total number of parts having extra 1 element
        
        ListNode *thead = head;
        vector<ListNode*> res;
        ListNode *aend = thead;
        
        //adding splitted LL into destination list having size of extra 1 
        for(int i = 0; i < extra_parts; i++)
        {
            res.push_back((thead!=NULL)?thead:NULL);
            aend = thead;
            for(int j = 0; j < (parts + 1); j++)
            {
                aend = thead;
                thead = thead->next;
            }
            aend?aend->next = NULL:NULL;
        }
        //adding equal size LL into destination list
        for(int i = 0; i < (k - extra_parts); i++)
        {
            res.push_back((thead!=NULL)?thead:NULL);
            aend = thead;
            for(int j = 0; j < parts; j++)
            {
                aend = thead;
                thead = thead->next;
            }
            aend?aend->next = NULL:NULL;
        }
        return res;
    }
};
