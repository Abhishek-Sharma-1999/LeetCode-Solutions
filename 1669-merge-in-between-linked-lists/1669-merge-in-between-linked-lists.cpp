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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* l1=list1; // for traversing of a
        ListNode* l2=list1; // for traversing of b
        ListNode* l3=list2; // for traversing of list2
        
        for(int i=0;i<a-1;i++)
        {
            l1=l1->next;
        }
        
        for(int i=0;i<b;i++)
        {
            l2=l2->next;
        }
        
        while(l3->next!=NULL)
        {
            l3=l3->next;
        }
        
        l1->next=list2; // connecting first list with second
        l3->next=l2->next;
        
        return list1;
        
    }
};