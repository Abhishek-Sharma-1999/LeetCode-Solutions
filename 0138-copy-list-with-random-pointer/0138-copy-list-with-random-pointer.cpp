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
        Node *newHead=new Node(0);  // A dummy node
        Node *returnHead=newHead;   //Head node,which we have to return
        Node *curr=head;    //for traversing
        map<Node*,Node*>mp;
        while(curr!=NULL)
        {
            Node *temp=new Node(curr->val);
            mp.insert({curr,temp}); //storing in map {old_node, new_node}
            newHead->next=temp;
            newHead=newHead->next;
            curr=curr->next;
        }
        curr=head; //re-initialising curr again to head,because it is pointing to NULL
        Node *duplicate=returnHead->next;   //jo duplicate node bnayi thi,uske head par jaane ke liye
        while(curr!=NULL)
        {
            Node *rand=curr->random;    //yhaan se orignal par jaayenge
            Node *new_random=mp[rand];  // map mein store hai, orignal ke saamne naya
            duplicate->random=new_random;   //duplicate ke trandom ko,map mein se nikalkar random ko point kra diya
            
            duplicate=duplicate->next;  //for duplicate traversing
            curr=curr->next;    //for orignal traversing
        }
        return returnHead->next;
    }
};