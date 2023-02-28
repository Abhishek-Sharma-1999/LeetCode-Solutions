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
    string Subtree_to_string(TreeNode* root,unordered_map<string,int> &mp,vector<TreeNode*> &ans)
    {
        if(root==NULL)
            return "N";
        string s=to_string(root->val) + "," + Subtree_to_string(root->left,mp,ans) + "," + Subtree_to_string(root->right,mp,ans);
        // agar vo(string) already,ek baar aa chuka hai toh ans vector mein push kar denge
        if(mp[s]==1)
            ans.push_back(root);
        // vo(string) first time aaya hai,toh map mein string ko store krayenge
        mp[s]++;
        
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mp;
        vector<TreeNode*>ans;
        Subtree_to_string(root,mp,ans);
        return ans;
    }
};