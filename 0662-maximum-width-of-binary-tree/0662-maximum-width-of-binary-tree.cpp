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
    typedef unsigned long long ll;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        ll MaxWidth=0;
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        while(!q.empty())
        {
            ll Left_most_index=q.front().second;
            ll Right_most_index=q.back().second;
            MaxWidth=max(MaxWidth,Right_most_index-Left_most_index+1);
            ll Size=q.size();
            for(ll i=0;i<Size;i++)
            {
                TreeNode *curr=q.front().first;
                ll Val=q.front().second;
                q.pop();
                if(curr->left!=NULL)
                    q.push({curr->left,2*Val+1});
                if(curr->right!=NULL)
                    q.push({curr->right,2*Val+2});
            }
        }
        return MaxWidth;
    }
};