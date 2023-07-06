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
    ListNode* removeNodes(ListNode* head) {
        stack<int>st;
        while(head!=NULL)
        {
            while(st.size()>0 && head->val>st.top())
            {
                st.pop();
            }
            st.push(head->val);
            head=head->next;
        }
        ListNode *curr=NULL;
        while(st.size()>0)
        {
            ListNode *temp=new ListNode(st.top());
            temp->next=curr;
            curr=temp;
            st.pop();
        }
        return curr;
    }
};