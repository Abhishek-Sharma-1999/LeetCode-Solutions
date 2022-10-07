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
    bool flag=true;
    int Height(TreeNode* root)
    {
        if(root==NULL)
        {
            return true;
        }
        int Left=Height(root->left);
        int Right=Height(root->right);
        
        if(abs(Left-Right)>1)
        {
            flag=false;
        }
        return 1+max(Left,Right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return 1;
        }
        Height(root);
        return flag;
    }
};