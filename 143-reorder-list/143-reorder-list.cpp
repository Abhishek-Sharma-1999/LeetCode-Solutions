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
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* secondList=reverse(slow->next);
        slow->next=NULL;
        ListNode* firstList=head;
        while(secondList!=NULL)
        {
            ListNode* temp1=firstList->next;
            ListNode* temp2=secondList->next;
            firstList->next=secondList;
            secondList->next=temp1;
            firstList=temp1;
            secondList=temp2;
        }
    }
};