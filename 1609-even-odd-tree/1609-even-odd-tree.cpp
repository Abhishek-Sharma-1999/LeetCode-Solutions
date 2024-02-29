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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool evenLevel=true;
        while(!q.empty())
        {
            int n=q.size(); //elements in current level
            int prev;
            if(evenLevel)
                prev=INT_MIN;
            else
                prev=INT_MAX;
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(evenLevel && (curr->val%2==0 || curr->val<=prev))
                    return false;
                if(!evenLevel && (curr->val%2!=0 || curr->val>=prev))
                    return false;
                prev=curr->val;
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
            evenLevel=!evenLevel;
        }
        return true;
    }
};