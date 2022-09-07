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
            return NULL;
        Node* newHead=new Node(0); // A dummy Node
        Node* returnHead=newHead;   // storing head of dummy node,to return 
        Node* curr=head;    //curr is pointing to orignal list,which we have to traverse
        unordered_map<Node*,Node*> umap; // map for strong addresses
        
        while(curr!=NULL)
        {
            Node* temp=new Node(curr->val);
            umap.insert({curr,temp});
            newHead->next=temp;
            newHead=newHead->next;
            curr=curr->next;
        }
        curr=head;
        Node* newCurr=returnHead->next;
        while(curr!=NULL)
        {
            Node* rand=curr->random;
            Node* newNode=umap[rand];
            newCurr->random=newNode;
            
            newCurr=newCurr->next;
            curr=curr->next;
        }
        return returnHead->next;
    }
};