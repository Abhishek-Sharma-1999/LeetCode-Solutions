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
    void reverse(ListNode* s,ListNode* e)
    {
        ListNode* prev=NULL;
        ListNode* curr=s;
        ListNode* nex=NULL;
        while(prev!=e)
        {
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==1)
            return head;
        ListNode *start=head;
        ListNode *end=head;
        int count=k-1;
        while(count--)
        {
            end=end->next;
            if(end==NULL)
                return head;
        }
        ListNode *NextHead=reverseKGroup(end->next,k);
        reverse(start,end);
        start->next=NextHead;
        return end;
        
    }
};