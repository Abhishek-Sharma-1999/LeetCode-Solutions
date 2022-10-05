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
    TreeNode* dummy=new TreeNode(-1);
    void helper(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        helper(root->left);
        root->left=NULL;
        dummy->right=root;
        dummy=root;
        helper(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *returnAns=dummy;
        helper(root);
        return returnAns->right;
    }
};