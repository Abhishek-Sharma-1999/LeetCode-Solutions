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
    int len(ListNode *head)
    {
        int l=0;
        while(head!=NULL)
        {
            head=head->next;
            l++;
        }
        return l;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int Length=len(head);
        vector<ListNode*> res;
        int partsize=Length/k;
        int extranode=Length%k;
        ListNode* curr=head;
        ListNode* prev=NULL;
        
        while(head!=NULL)
        {
            int currpart=partsize;
            res.push_back(curr);
            while(currpart>0)
            {
                prev=curr;
                curr=curr->next;
                currpart--;
            }
            
            if(extranode!=0 && curr!=NULL)
            {
                extranode--;
                prev=curr;
                curr=curr->next;
            }
            
            if(prev!=NULL)
            {
                head=curr;
                prev->next=NULL;
            }
        }
        
        while(res.size()!=k)
        {
            res.push_back(NULL);
        }
        
        return res;
        
    }
};