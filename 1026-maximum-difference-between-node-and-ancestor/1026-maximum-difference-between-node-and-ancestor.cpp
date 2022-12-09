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
    int help(TreeNode* root,int mini,int maxi)
    {
        // Base Condition, if we are on NULL, we return diffference of maximum alue-minimum value we have find on that path
        if(root==NULL)
        {
            return abs(maxi-mini);
        }
        // Updating Minimum and Maximum value
        maxi=max(root->val,maxi);
        mini=min(root->val,mini);
        // Traversal
        int Left=help(root->left,mini,maxi);
        int Right=help(root->right,mini,maxi);
        
        return max(Left,Right); 
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        
        return help(root,INT_MAX,INT_MIN);
    }
};