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
    int helper(TreeNode* root,unordered_map<int,int>& mp,int &maxFrequency)
    {
        if(root==NULL)
            return 0;
        int Left=helper(root->left,mp,maxFrequency);
        int Right=helper(root->right,mp,maxFrequency);
        
        int Curr=Left+Right+root->val;  //Current Node Sum
        mp[Curr]++;
        
        if(mp[Curr]>maxFrequency)   //agar current node ke sum ki frequency,zayada aayi toh store kra lenge
        {
            maxFrequency=mp[Curr];
        }
        return Curr;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        int maxFrequency=0;
        unordered_map<int,int> mp;  //for storing node's sum and their frequency
        helper(root,mp,maxFrequency);
        for(auto i:mp)
        {
            if(i.second==maxFrequency)
            {
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};