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
    void getSum(TreeNode* root, int targetSum, vector<vector<int>>& ans,vector<int> temp)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL && targetSum==root->val)
        {
            temp.push_back(root->val);
            ans.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        getSum(root->left,targetSum-root->val,ans,temp);
        getSum(root->right,targetSum-root->val,ans,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        getSum(root,targetSum,ans,temp);
        return ans;
    }
};