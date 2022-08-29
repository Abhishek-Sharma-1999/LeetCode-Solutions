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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode(-300000);
        while(head!=NULL)
        {
            ListNode* nex=head->next;
            ListNode* temp=dummy;
            
            while(temp->next!=NULL && temp->next->val<head->val)
            {
                temp=temp->next;
            }
            head->next=temp->next;
            temp->next=head;
            head=nex;
        }
        
        return dummy->next;
    }
    
};