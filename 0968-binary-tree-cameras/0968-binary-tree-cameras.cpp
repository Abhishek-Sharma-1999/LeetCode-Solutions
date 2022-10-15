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
    //1-monitored       2-//camera      0-camera not installed and not monitored
    int Rec(TreeNode* root,int& sum)
    {
        if(root==NULL)
        {
            return 1;
        }
        
        int Left=Rec(root->left,sum);
        int Right=Rec(root->right,sum);
        
        if(Left==0 || Right==0)
        {
            sum++;
            return 2;
        }
        
        else if(Left==2 || Right==2)
        {
            return 1;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int sum=0;
        int ans=Rec(root,sum);
        if(ans==0)  //if only single root is there  [Root] then we have to monitor it
        {
            sum++;
        }
        return sum;
    }
};