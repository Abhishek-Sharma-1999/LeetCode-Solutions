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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        ListNode* returnHead=dummy;
        head=head->next;
        int currSum=0;
        while(head!=NULL)
        {
            if(head->val!=0)
            {
                currSum+=head->val;
            }
            else
            {
                ListNode* temp=new ListNode(currSum);
                currSum=0;
                dummy->next=temp;
                dummy=dummy->next;
            }
            head=head->next;
        }
        return returnHead->next;
    }
};