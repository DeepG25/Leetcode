/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

//Solution
//Time complexity - O(min(n,m)) where n,m are lengths of linked lists
//Space complexity - O(n+m)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newhead;
        if(l1==NULL)    return l2;
        if(l2==NULL)    return l1;
        ListNode* s;
        if(l1->val < l2->val)
        {
            s = l1;
            l1 = l1->next;
        }
        else
        {
            s = l2;
            l2 = l2->next;
        }
        newhead = s;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                s->next = l1;
                l1 = l1->next;
                s = s->next;
            }
            else
            {
                s->next = l2;
                l2 = l2->next;
                s = s->next;
            }
        }
        if(!l1)
        {
            s->next = l2;
        }
        if(!l2)
        {
            s->next = l1;
        }
        return newhead;
    }
};
