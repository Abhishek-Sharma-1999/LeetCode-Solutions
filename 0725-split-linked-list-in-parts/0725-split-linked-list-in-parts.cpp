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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>res(k,NULL);
        int len=0;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            len++;
            curr=curr->next;
        }
        int parts=len/k;
        int extraNodes=len%k;
        ListNode *prev=NULL;
        curr=head;
        for(int i=0;i<k && curr!=NULL;i++)
        {
            res[i]=curr;
            for(int count=1;count<=parts+(extraNodes>0?1:0);count++)
            {
                prev=curr;
                curr=curr->next;
            }
            prev->next=NULL;
            extraNodes--;
        }
        return res;
    }
};