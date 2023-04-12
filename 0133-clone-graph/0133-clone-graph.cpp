/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mp;
    void DFS(Node* node,Node* clone_node)
    {
        for(Node* n:node->neighbors)
        {
            if(mp.find(n)==mp.end())    //iska clone abhi nahi bnaya hai
            {
                // toh pehle clone bna lete hai
                Node *clone=new Node(n->val);
                mp[n]=clone; //purani node ke address ke corresponding new_clone_node ka address
                // aur ye _neighbors hoga ab clone node ka,toh neighbors vector mein ise push kar denge
                clone_node->neighbors.push_back(clone);
                DFS(n,clone);
            }
            else    //iska clone bna hua hai already ,toh bas use clone_node ke neighbor mein push kar denge,aur uski value map mein orignal_node ke corresponding mil jaayegi
            {
                clone_node->neighbors.push_back(mp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        Node *clone_node=new Node(node->val);
        mp[node]=clone_node;  //purani node ke address ke corresponding new_clone_node ka address
        DFS(node,clone_node);
        return clone_node;
        
    }
};