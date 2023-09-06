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
    int len(ListNode* head)
    {
        int n=0;
        while(head!=NULL)
        {
            head=head->next;
            n++;
        }
        return n;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int Length=len(head);
        vector<ListNode*>res;
        int partSize=Length/k;
        int extraNodes=Length%k;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(head!=NULL)
        {
            int currPart=partSize;
            res.push_back(curr);
            while(currPart>0)
            {
                prev=curr;
                curr=curr->next;
                currPart--;
            }
            if(extraNodes!=0 && curr!=NULL)
            {
                extraNodes--;
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