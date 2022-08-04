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
    ListNode* deleteDuplicates(ListNode* head) {
     ListNode* dummy=new  ListNode();
        dummy->next=head;
        ListNode* prev=dummy;
        
        while(head!=NULL)
        {
            if(head->next!=NULL && head->val==head->next->val)
            {
                while(head->next!=NULL && head->val==head->next->val)
                {
                    head=head->next;
                }
                prev->next=head->next;
                head=head->next;
            }
            else
            {
                head=head->next;
                prev=prev->next;
            }
        }
        return dummy->next;
    }
};