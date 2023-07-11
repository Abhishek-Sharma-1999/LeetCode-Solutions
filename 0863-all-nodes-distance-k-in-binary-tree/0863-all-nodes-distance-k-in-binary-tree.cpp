/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>parent;
    void addParent(TreeNode* root)  //Adding Parent
    {
        // doing normal inorder traversal and making the parent of node
        if(root==NULL)
            return;
        
        if(root->left!=NULL)
            parent[root->left]=root;
        
        addParent(root->left);
        
        if(root->right!=NULL)
            parent[root->right]=root;
        
        addParent(root->right);
    }
    
    void collectKdistanceNodes(TreeNode* target,int k,vector<int>& res)
    {
        queue<TreeNode*>q;
        q.push(target);
        unordered_set<int>visited;
        visited.insert(target->val);
        while(!q.empty())
        {
            int n=q.size();
            if(k==0)
                break;
            while(n--)
            {
                TreeNode* curr=q.front();
                q.pop();
                // inserting leftnode in the queue,if it is not visited
                if(curr->left!=NULL && !visited.count(curr->left->val))
                {
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }
                // inserting rightnode in the queue, if it is not visited
                if(curr->right!=NULL && !visited.count(curr->right->val))
                {
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }
                //inserting it's parent in the queue, if it is not visited
                if(parent.count(curr) && !visited.count(parent[curr]->val))
                {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }
        // jab hum loop se bahar nikalenge tab,usmein sirf k level vaale nodes, jo target se dur hain vahin honge
        while(!q.empty())
        {
            TreeNode *u=q.front();
            q.pop();
            res.push_back(u->val);
        }
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;
        addParent(root);
        collectKdistanceNodes(target,k,res);
        return res;
    }
};