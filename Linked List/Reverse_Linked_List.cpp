/*

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

*/

//Solution
//time complexity - O(n)
//space complexity - O(1)

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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* ne = NULL;
        while(head!=NULL)
        {
            ne = head->next;
            head->next = pre;
            pre = head;
            head = ne;
        }
        return pre;
    }
};
