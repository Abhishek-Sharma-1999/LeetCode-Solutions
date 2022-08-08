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
    int answer=0;
    void Solve(TreeNode* root,int k,int &count)
    {
        if(root==NULL)
            return;
        Solve(root->left,k,count);
        count++;
        if(count==k)
        {
            answer=root->val;
            return;
        }
        Solve(root->right,k,count);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        Solve(root,k,count);
        return answer;
    }
};