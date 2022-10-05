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
    void Solve(TreeNode* root,vector<int>& ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(root->val);
        }
        Solve(root->left,ans);
        Solve(root->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>path1;
        vector<int>path2;
        Solve(root1,path1);
        Solve(root2,path2);
        
        int n1=path1.size(),n2=path2.size();
        if(n1!=n2)
        {
            return false;
        }
        for(int i=0;i<n1;i++)
        {
            if(path1[i]!=path2[i])
            {
                return false;
            }
        }
        return true;
    }
};