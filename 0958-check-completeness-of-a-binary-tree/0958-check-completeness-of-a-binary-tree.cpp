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
    bool isCompleteTree(TreeNode* root) {
        // BFS
        if(root==NULL)
        {
            return true;
        }
        bool prev=false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* u=q.front();
            q.pop();
            if(u==NULL)
            {
                prev=true;
            }
            else
            {
                if(prev)
                {
                    return false;
                }
                q.push(u->left);
                q.push(u->right);
            }
        }
        return true;
    }
};