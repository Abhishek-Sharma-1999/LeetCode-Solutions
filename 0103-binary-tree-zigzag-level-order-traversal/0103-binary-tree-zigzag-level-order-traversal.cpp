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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<TreeNode*>q;
        int count=0;
        vector<vector<int>> res;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp;
            int Size=q.size();
            count++;
            for(int i=0;i<Size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
            if(count%2==0)
            {
                reverse(temp.begin(),temp.end());
            }
            res.push_back(temp);
        }
        return res;
    }
};