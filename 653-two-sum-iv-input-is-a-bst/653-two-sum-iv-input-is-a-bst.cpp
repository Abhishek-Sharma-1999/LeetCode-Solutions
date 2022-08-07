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

    vector<int> nums;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        
            inorder(root->left);
            nums.push_back(root->val);
            inorder(root->right);
        
    }
    public:
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            int sum=nums[i]+nums[j];
            if(sum==k)
                return true;
            else if(sum>k)
                j--;
            else
                i++;
        }
        return false;
    }
};