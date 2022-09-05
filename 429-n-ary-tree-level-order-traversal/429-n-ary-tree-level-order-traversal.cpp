/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)
        {
            return {};
        }
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                Node* curr=q.front();
                q.pop();
                temp.push_back(curr->val);
                
                for(auto i:curr->children)
                    q.push(i);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};