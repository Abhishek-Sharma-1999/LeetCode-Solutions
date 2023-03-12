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
    
    ListNode* mergeTwoSortedLists(ListNode *l1,ListNode *l2)
    {
        if(l1==NULL)
            return l2;
        
        if(l2==NULL)
            return l1;
        
        if(l1->val<=l2->val)
        {
            l1->next=mergeTwoSortedLists(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=mergeTwoSortedLists(l2->next,l1);
            return l2;
        }
        return NULL;
    }
    
    ListNode *partitionAndMerge(int start,int end,vector<ListNode*>& lists)
    {
        if(start>end)
            return NULL;
        
        if(start==end)  //agar ek hi list hai
            return lists[start];
        
        int mid=start+(end-start)/2;
        ListNode *List1=partitionAndMerge(start,mid,lists);
        ListNode *List2=partitionAndMerge(mid+1,end,lists);
        return mergeTwoSortedLists(List1,List2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       // Approach-1
        // vector<int> ans;
        // for(int i=0;i<lists.size();i++)
        // {
        //     while(lists[i]!=NULL)
        //     {
        //         ans.push_back(lists[i]->val);
        //         lists[i]=lists[i]->next;
        //     }
        // }
        // sort(ans.begin(),ans.end());
        // ListNode *dummy=new ListNode();
        // ListNode *start=dummy;
        // for(int i=0;i<ans.size();i++)
        // {
        //     ListNode *temp=new ListNode(ans[i]);
        //     dummy->next=temp;
        //     dummy=dummy->next;
        // }
        // return start->next;
        
        //Approach-2
        int k=lists.size();
        if(k==0)
            return NULL;
        return partitionAndMerge(0,k-1,lists);
        
    }
};