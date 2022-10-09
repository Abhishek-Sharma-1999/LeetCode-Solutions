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
    int bottomLeft=0,Lowest_level=-1;
    void dfs(TreeNode* root,int level)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(level>Lowest_level)
        {
            Lowest_level=level;
            bottomLeft=root->val;
        }
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,0);
        return bottomLeft;
    }
};