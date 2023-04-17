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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum=0;
        ListNode* start=head;
        ListNode* dummy=new ListNode(0);   // a dummy node
        dummy->next=head;
        unordered_map<int,ListNode*>mp;
        mp[dummy->val]=dummy; // mp[0]=dummy    ->For Edge Case
        while(start!=NULL)
        {
            prefixSum=prefixSum+start->val;
            if(mp.find(prefixSum)!=mp.end())   //map mein value already exist karti hai,toh vo jhaan last tme exist karti hogi,vhaan se start karenge aur current node tak aayenge,un nodes ko delete karte hue, matlab pointer ko unke aage point kra denge, aur saath mein un values ko map mein se bhi remove kar denge
            {
                ListNode *Delete=mp[prefixSum]; //ye vo node hai,jiski value already exist karti hai,toh is node se start karenge
                ListNode* temp=Delete;  //another node,kyunki vali ke next ko start ke next ko point krana hai,toh isse traverse karenge
                int pre_sum=prefixSum;
                while(temp!=start)
                {
                    temp=temp->next;
                    pre_sum+=temp->val;
                    if(temp!=start) //hme jhaan par same value mili hai,map mein hmne use store nahin karvaya hai,toh jab tak uske equal nahin aa jate , beech ki saari values ko remove kar denge
                    {
                        mp.erase(pre_sum);
                    }
                }
                Delete->next=start->next;
            }
            else    //map mein value exist nahin karti,toh value ko map mein store kra lenge
            {
                mp[prefixSum]=start;
            }
            start=start->next;
        }
        return dummy->next;
    }
};