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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *fast=head;
        while(--k)
        {
            fast=fast->next;
        }
        ListNode *start=head;
        ListNode *temp=fast;
        while(fast->next!=NULL)
        {
            start=start->next;
            fast=fast->next;
        }
        swap(start->val,temp->val);
        return head;
    }
};