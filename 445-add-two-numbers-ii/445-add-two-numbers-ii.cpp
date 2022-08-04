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
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        
        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a=reverse(l1);
        ListNode* b=reverse(l2);
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int c=0;
        while(a || b|| c)
        {
            int sum=0;
            if(a!=NULL)
            {
                sum+=a->val;
                a=a->next;
            }
            
            if(b!=NULL)
            {
                sum+=b->val;
                b=b->next;
            }
            sum=sum+c;
            c=sum/10;
            ListNode* m=new ListNode(sum%10);
            temp->next=m;
            temp=temp->next;
        }
         ListNode* ans=reverse(dummy->next);
        return ans;
    }
};