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
    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode* solve(int low,int high,vector<int>&ans)
    {
        if(low>high)
            return NULL;
        int mid=low+(high-low)/2;
        TreeNode* root=new TreeNode(ans[mid]);
        root->left=solve(low,mid-1,ans);
        root->right=solve(mid+1,high,ans);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return solve(0,ans.size()-1,ans);
    }
};