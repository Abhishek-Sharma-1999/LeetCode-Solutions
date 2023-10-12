//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution{

public:
    int floor(Node* root, int x) {
        int ans=-1;
        while(root!=NULL)
        {
            if(x==root->data)   //agar root->data equal hai x ke, toh vahi return kar denge
            {
                ans=root->data;
                return ans;
            }
            else if(x<root->data)   //agar x chota hai, root ke data se, matlab usse badi value available hai, toh right mein jaayenge
            {
                root=root->left;
            }
            else if(x>root->data) //agar x bda hai, root ke data se, toh right jaayenge, par ho sakta hai right jaane ke baad aur bhi badi value mil jaaye x se, toh ans mein root->data ko store kra lenge
            {
                ans=root->data;
                root=root->right;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends