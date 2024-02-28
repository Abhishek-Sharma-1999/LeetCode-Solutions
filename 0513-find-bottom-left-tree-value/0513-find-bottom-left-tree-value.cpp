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
    int maxDepth=-1;
    int res=0;
    void solve(TreeNode* root,int currDepth){
        if(!root){
            return;
        }
        if(currDepth>maxDepth){
            maxDepth=currDepth;
            res=root->val;
        }
        solve(root->left,currDepth+1);
        solve(root->right,currDepth+1);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        int currDepth=0;
        solve(root,currDepth);
        return res;
    }
};