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
    int help(TreeNode* root,int &maxi)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=max(0,help(root->left,maxi));
        int right=max(0,help(root->right,maxi));
        int curr=root->val+left+right;
        maxi=max(maxi,curr);
        return root->val+max(left,right);
        
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        help(root,ans);
        return ans;
    }
};