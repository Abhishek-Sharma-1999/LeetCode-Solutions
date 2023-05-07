//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        Node *even=new Node(0); // a dummy node
        Node *odd=new Node(-1);
        Node *res1=even;
        Node *res2=odd;
        Node *curr=head;    //for traversing
        while(curr!=NULL)
        {
            if(curr->data % 2==0)   //even node
            {
                even->next=curr;
                even=even->next;
            }
            else    //odd node
            {
                odd->next=curr;
                odd=odd->next;
            }
            curr=curr->next;
        }
        odd->next=NULL; //now odd->next should point to null
        even->next=res2->next; //even->next should point to odd->head
        return res1->next;  //we are returning dummy->next
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends