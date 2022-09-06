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
    void Recursion(TreeNode* root,int level,vector<int>& ans)
    {
        // Reverse (Root-Right-Left)
        if(root==NULL)
            return;
        if(level==ans.size())
            ans.push_back(root->val);
        Recursion(root->right,level+1,ans);
        Recursion(root->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        Recursion(root,0,ans);
        return ans;
    }
};