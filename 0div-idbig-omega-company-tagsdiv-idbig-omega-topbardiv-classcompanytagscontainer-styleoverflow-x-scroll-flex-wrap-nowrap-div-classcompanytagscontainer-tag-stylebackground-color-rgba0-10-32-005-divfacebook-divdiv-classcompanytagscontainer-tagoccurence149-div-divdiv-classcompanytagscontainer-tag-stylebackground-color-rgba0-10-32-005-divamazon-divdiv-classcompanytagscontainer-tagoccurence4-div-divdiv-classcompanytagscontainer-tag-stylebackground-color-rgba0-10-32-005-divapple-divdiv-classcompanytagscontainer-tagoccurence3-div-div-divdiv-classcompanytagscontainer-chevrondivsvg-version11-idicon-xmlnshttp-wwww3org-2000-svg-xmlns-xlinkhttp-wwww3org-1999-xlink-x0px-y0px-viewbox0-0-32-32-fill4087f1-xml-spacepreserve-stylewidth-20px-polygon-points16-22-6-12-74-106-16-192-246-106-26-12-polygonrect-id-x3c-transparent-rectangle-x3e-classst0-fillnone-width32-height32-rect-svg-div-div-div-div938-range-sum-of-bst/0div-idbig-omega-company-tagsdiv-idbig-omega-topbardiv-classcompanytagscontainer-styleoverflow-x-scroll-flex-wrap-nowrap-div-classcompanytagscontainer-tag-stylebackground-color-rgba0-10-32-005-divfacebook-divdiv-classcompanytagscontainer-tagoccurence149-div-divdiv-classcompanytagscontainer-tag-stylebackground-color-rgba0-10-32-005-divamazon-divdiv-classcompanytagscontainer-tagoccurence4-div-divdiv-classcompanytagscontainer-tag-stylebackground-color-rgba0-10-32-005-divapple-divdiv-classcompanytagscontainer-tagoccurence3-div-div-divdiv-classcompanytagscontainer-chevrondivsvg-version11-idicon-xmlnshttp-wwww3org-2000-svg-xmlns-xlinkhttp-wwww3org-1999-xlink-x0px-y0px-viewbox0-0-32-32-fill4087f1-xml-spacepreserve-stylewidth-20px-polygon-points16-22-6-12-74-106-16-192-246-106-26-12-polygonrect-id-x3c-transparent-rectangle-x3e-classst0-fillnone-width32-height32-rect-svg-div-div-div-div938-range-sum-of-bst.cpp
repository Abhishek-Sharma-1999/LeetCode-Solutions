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
    // int sum=0;
    // int inorder(TreeNode* root, int low, int high)
    // {
    //     if(root==NULL)
    //         return 0;
    //     inorder(root->left,low,high);
    //     if(root->val>=low && root->val<=high)
    //         sum+=root->val;
    //     inorder(root->right,low,high);
    //     return sum;
    // }
    int rangeSumBST(TreeNode* root, int low, int high) {
       //Approach-1 (In-Order Traversal)
        // inorder(root,low,high);
        // return sum;
        
        // Approach-2 (Without have to traverse all the nodes)
        if(root==NULL)
        {
            return 0;
        }
        int ans=0;
        if(root->val>=low && root->val<=high)
        {
            ans+=root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
            return ans;
        }
        if(root->val>high)
        {
            return rangeSumBST(root->left,low,high);
        }
        else
        {
            return rangeSumBST(root->right,low,high);
        }
        return ans;
    }
};