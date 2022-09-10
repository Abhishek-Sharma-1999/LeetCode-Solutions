/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void traverse(TreeNode* root,string ans,vector<string> &res)
    {
        if(root==NULL)
        {
            return ;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            ans+=to_string(root->val);
            res.push_back(ans);
            return;
        }
        
        ans+=to_string(root->val)+ "->";
        traverse(root->left,ans,res);
        traverse(root->right,ans,res);       
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        traverse(root,"",res);
        return res;
    }
};