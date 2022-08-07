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
    void inorder(TreeNode* root, vector<int>& vec){
        if(!root) return;
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        vector<int> vec;
        inorder(root,vec);
        int l=0,r=vec.size()-1;
        while(l<r){
            int sum=vec[l]+vec[r];
            if(sum<k) l++;
            else if(sum>k) r--;
            else return true;
        }
        return false;
    }
};