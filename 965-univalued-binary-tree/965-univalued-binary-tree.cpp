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
    bool check(TreeNode* root,int value)
    {
        if(root==NULL)
        {
            return 1;
        }
        if(root->val!=value)
        {
            return false;
        }
        
        return check(root->left,value) && check(root->right,value);
    }
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        return check(root,root->val);
    }
};