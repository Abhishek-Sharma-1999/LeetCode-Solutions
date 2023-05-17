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
    int pairSum(ListNode* head) {
        // vector<int>ans;
        // while(head!=NULL){
        //     ans.push_back(head->val);
        //     head=head->next;
        // }
        // int i=0,j=ans.size()-1,res=INT_MIN;
        // while(i<j)
        // {
        //     int sum=ans[i]+ans[j];
        //     res=max(sum,res);
        //     i++;
        //     j--;
        // }
        // return res;
        
        // Approach-2 //half part ko baad mein hai,use reverse kar denge, phir 2 pointer chlayenge ek head se aur ek reverse vaale part se aur sum lete hue chalenge,aur jaise hi reverse part vaala pointer null pe hoga, ruk jaayenge
        ListNode *slow=head;
        ListNode *fast=head;
       // calculating middle of linked list 
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        // reversing next half part of linked list
        ListNode *mid=slow;
        ListNode *prev=NULL,*forward=NULL;
        while(mid!=NULL){
            forward=mid->next;
            mid->next=prev;
            prev=mid;
            mid=forward;
        }
        // now calculating the result
        int res=0;
        ListNode*first=head;    //pointer of first node
        // pointer of head of second list will be prev
        while(prev!=NULL){
            res=max(res,first->val+prev->val);
            first=first->next;
            prev=prev->next;
        }
        return res;
    }
};