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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1=new ListNode();
        ListNode* dummy2=new ListNode();
        ListNode* ans1=dummy1;
        ListNode* ans2=dummy2;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            if(curr->val < x)
            {
                dummy1->next=curr;
                dummy1=dummy1->next;
            }
            else
            {
                dummy2->next=curr;
                dummy2=dummy2->next;
            }
            curr=curr->next;
        }
        dummy1->next=ans2->next;
        dummy2->next=NULL;
        return ans1->next;
        

    }
};