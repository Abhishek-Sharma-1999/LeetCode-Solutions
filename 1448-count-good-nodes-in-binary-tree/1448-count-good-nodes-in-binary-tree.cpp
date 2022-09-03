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
    int count=0;
    void preorder(TreeNode* root,int CurrMax)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->val >= CurrMax)
        {
            count++;
            CurrMax=root->val;
        }
        preorder(root->left,CurrMax);
        preorder(root->right,CurrMax);
    }
    int goodNodes(TreeNode* root) {
        
        preorder(root,root->val);
        return count;
    }
};