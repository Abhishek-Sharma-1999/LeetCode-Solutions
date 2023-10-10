//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    unordered_map<Node*,Node*>mp;
    Node *Target=NULL;  //target node ke address store krane ke liye, hame integer given hai
    
    void inorder(Node* root,int target) //for marking the parent
    {
        if(root==NULL)
        {
            return;
        }
        if(root->data==target)
        {
            Target=root;
        }
        if(root->left!=NULL)
        {
            mp[root->left]=root;
            inorder(root->left,target);
        }
        if(root->right!=NULL)
        {
            mp[root->right]=root;
            inorder(root->right,target);
        }
    }
    
    void BFS(Node* root,int k,vector<int>& ans)
    {
        queue<Node*>q;
        q.push(root);
        unordered_set<int>visited;
        visited.insert(root->data);
        while(!q.empty())
        {
            int n=q.size();
            if(k==0)
            {
                break;
            }
            while(n--)
            {
                Node *temp=q.front();
                q.pop();
                if(temp->left!=NULL && !visited.count(temp->left->data))    //for traversing-left
                {
                    q.push(temp->left);
                    visited.insert(temp->left->data);
                }
                
                if(temp->right!=NULL && !visited.count(temp->right->data))    //for traversing-Right
                {
                    q.push(temp->right);
                    visited.insert(temp->right->data);
                }
                
                if(mp.count(temp) && !visited.count(mp[temp]->data))  //agar is node ka parent hai, aur vo visitedbhi nahin hai
                {
                    q.push(mp[temp]);
                    visited.insert(mp[temp]->data);
                }
            }
            k--;
        }
        
        while(!q.empty())
        {
            ans.push_back(q.front()->data);
            q.pop();
        }
    }
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int>ans;
        inorder(root,target);
        BFS(Target,k,ans);  //hum taget node ke addresss se Traversal ko start karenge
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends