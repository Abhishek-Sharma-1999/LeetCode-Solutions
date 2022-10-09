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
    
   
    int maxDepth(Node* root) {
        int max_Level=0;
        if(root==NULL)
        {
            return 0;
        }
        for(auto child:root->children)
        {
            max_Level=max(max_Level,maxDepth(child));
        }
        return max_Level+1;
    }
};