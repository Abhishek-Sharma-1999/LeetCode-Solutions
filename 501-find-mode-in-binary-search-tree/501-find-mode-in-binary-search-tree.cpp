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
    void inorder(TreeNode* root,unordered_map<int,int> &mp)
    {
        if(root==NULL)
            return;
        inorder(root->left,mp);
        mp[root->val]++;
        inorder(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int freq=INT_MIN;
        unordered_map<int,int> mp;
        inorder(root,mp);
        for(auto i:mp)
        {
            freq=max(freq,i.second);
        }
        
        for(auto i:mp)
        {
            if(i.second==freq)
                res.push_back(i.first);
        }
        
        return res;
    }
};