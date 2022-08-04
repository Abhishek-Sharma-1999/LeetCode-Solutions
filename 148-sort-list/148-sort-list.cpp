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
    ListNode* sortList(ListNode* head) {
        ListNode* curr=head;
        vector<int> ans;
        while(curr!=NULL)
        {
            ans.push_back(curr->val);
            curr=curr->next;
        }
        sort(ans.begin(),ans.end());
        ListNode* dummy=new ListNode();
        ListNode* tail=dummy;
        for(int i=0;i<ans.size();i++)
        {
            ListNode* n=new ListNode(ans[i]);
            tail->next=n;
            tail=tail->next;
        }
        return dummy->next;
    }
};