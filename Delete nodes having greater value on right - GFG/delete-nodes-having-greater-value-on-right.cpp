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
    public:
    Node *compute(Node *head)
    {
        Node *temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data < temp->next->data)
            {
                temp->data=temp->next->data;    //copying next greater value to current node data
                Node *del=temp->next;   //this is next node,whose data has been copied,now we delete that node
                temp->next=temp->next->next; //pointing curr node next to curr next' next
                delete(del);    //deleting the next node,whose data has been copied
                temp=head;  // re-initialising temp again to head, taaki jo abhi node bnayi hai,kabhi vo choti nikle aage vaalo se, is liye temp=temp->next nahin kiya
            }
            else
            {
                temp=temp->next; //nahin toh normally aage bda denge
            }
        }
        return head; //temp toh last mein chla gya hoga,isliye head ko return kra denge
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