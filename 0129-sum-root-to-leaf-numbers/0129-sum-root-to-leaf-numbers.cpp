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
    int help(TreeNode* root,int num)
    {
        if(root==NULL)
            return 0;
        num=(num*10)+(root->val);
        // leaf node par hain,toh num ko hi return kar denge,vo update ho chuka hoga upar vaali line se
        if(root->left==NULL && root->right==NULL)
        {
            return num;
        }
        int left=help(root->left,num);
        int right=help(root->right,num);
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        int num=0;
        return help(root,num);
    }
};