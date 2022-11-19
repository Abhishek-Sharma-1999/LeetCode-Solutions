/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return head;
        Node* newHead=new Node(0);  // A dummy Node
        Node* returnHead=newHead;   //Head Node which we have to return
        Node* curr=head;    // for Traversing
        map<Node*,Node*> mp;
        while(curr!=NULL)
        {
            Node* temp=new Node(curr->val);
            mp.insert({curr,temp});
            newHead->next=temp;
            newHead=newHead->next;
            curr=curr->next;
        }
        curr=head; //after traversing, curr will point to NULL, so again initialising it with head
        Node* newCurr=returnHead->next;
        while(curr!=NULL)
        {
            Node* rand=curr->random;
            Node* newrand=mp[rand];
            newCurr->random=newrand;
            
            newCurr=newCurr->next;
            curr=curr->next;    
        }
        return returnHead->next;
    }
};