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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp=head;
        vector<int> ans;
        while(head!=NULL)
        {
            int curr=head->val;
            temp=head;
            while(temp!=NULL)
            {
                if(temp->val>curr)
                {
                    ans.push_back(temp->val);
                    break;
                }
                temp=temp->next;
            }
            if(temp==NULL)
            {
                ans.push_back(0);
            }
            head=head->next;
        }
        return ans;
    }
};