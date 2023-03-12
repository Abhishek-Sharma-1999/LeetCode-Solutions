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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       // Approach-1
        vector<int> ans;
        for(int i=0;i<lists.size();i++)
        {
            while(lists[i]!=NULL)
            {
                ans.push_back(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        sort(ans.begin(),ans.end());
        ListNode *dummy=new ListNode();
        ListNode *start=dummy;
        for(int i=0;i<ans.size();i++)
        {
            ListNode *temp=new ListNode(ans[i]);
            dummy->next=temp;
            dummy=dummy->next;
        }
        return start->next;
        
    }
};