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
    bool Match(TreeNode *root1,TreeNode *root2)
    {
        // if(root1!=NULL && root2!=NULL)
        // {
        //     bool a=Match(root1->left,root2->right);
        //     bool b=Match(root1->right,root2->left);
        //     if(root1->val==root2->val && a && b)
        //         return true;
        //     else
        //         return false;
        // }
        // else if(root1==NULL && root2==NULL)
        //     return true;
        // else
        //     return false;
        if(root1==NULL && root2==NULL)
            return true;
        // dono NUll ho ye condition upar hi hmne check karli,matlab ab ek null nahin hai
        if(root1==NULL || root2==NULL)
            return false;
        if((root1->val==root2->val) && Match(root1->left,root2->right) && Match(root1->right,root2->left))
            return true;
        // agar iske alava kuch bhi hai,toh return false
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return Match(root->left,root->right);
    }
};