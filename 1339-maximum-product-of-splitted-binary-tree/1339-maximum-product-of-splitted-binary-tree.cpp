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
    long long int Total_sum=0;
    long long int ans=0;
    long long int MOD=1e9+7;
    long long int Curr_sum=0;
    void Traversal(TreeNode* root)
    {
        if(root==NULL)
            return;
        Traversal(root->left);
        Total_sum=(Total_sum+root->val)%MOD;
        Traversal(root->right);
    }
    int Prod(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        Curr_sum=root->val%MOD+Prod(root->left)%MOD+Prod(root->right)%MOD;
        ans=max(ans,Curr_sum*(Total_sum-Curr_sum));
        return Curr_sum;
    }
public:
    int maxProduct(TreeNode* root) {
        Traversal(root);
        Prod(root);
        return ans%MOD;
    }
};