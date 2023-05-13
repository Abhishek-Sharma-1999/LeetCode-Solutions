//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    Node *reverse(Node *head)
    {
        Node *prev=NULL;
        Node *curr=head;
        Node *forward=NULL;
        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return head;
    }
    public:
    Node *compute(Node *head)
    {
        Node *temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data < temp->next->data)
            {
                temp->data=temp->next->data;    //Copying the data from next node to current
                Node *curr=temp->next;  // this is the next node,that has to be deleted
                temp->next=temp->next->next;
                delete curr;    //us node ko delete kar diya
                temp=head;  //temp ko dobara head par le aaye, ki jo pehle ki node thi kabhi vo choti hui, jo node abhi bani aage ke pointers sab sorted hain,isliye ham dobara head par aa gaye
            }
            else
            {
                temp=temp->next;
            }
        }
        return head;
        
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends