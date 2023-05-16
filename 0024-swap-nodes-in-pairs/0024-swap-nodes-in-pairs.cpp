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
    ListNode* swapPairs(ListNode* head) {
        // Using Recursion
        if(head==NULL || head->next==NULL)  //agar koi node hai hi nahin ya sirf ek hi node hai,toh head ko hi return kar denge
            return head;
        ListNode *temp=head->next;  //hum head ke next ko head ke next ke next par leke jaaayenge , toh agli node kahin lost na ho jaaye,toh ise ek node mein store kra lenge
        
        head->next=swapPairs(head->next->next); //head ke next mein head ke next ka next aayega, vo swap ho gye honge(assume karte hain) to hum head ke next ko use point kr denge
        
        temp->next=head; // ab josecond node tha(jisse store kraya tha) uske next mein head ko point kra denge
        return temp;    //phir second node ko hi return kra denge
    }
};