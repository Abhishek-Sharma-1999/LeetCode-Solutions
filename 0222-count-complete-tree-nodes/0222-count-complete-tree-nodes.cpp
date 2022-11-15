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
    // Using Any Traversal as it will also count the node
    // int count=0;
    // void inorder(TreeNode* root)
    // {
    //     if(root==NULL)
    //         return;
    //     inorder(root->left);
    //     count++;
    //     inorder(root->right);
    // }
    int countNodes(TreeNode* root) {
        // inorder(root);
        // return count;
    
    // 2-Approach
    if(root==NULL)
        return 0;
     int Left_Height=0,Right_Height=0;
    TreeNode *curr=root;
    // Calculating Left Height
    while(curr!=NULL)
    {
        Left_Height++;
        curr=curr->left;
    }
        curr=root;
    // Calculating Right Height
    while(curr!=NULL)
    {
        Right_Height++;
        curr=curr->right;
    }
    
    if(Left_Height==Right_Height)
    {
        return pow(2,Left_Height)-1;    //2^h -1, where h is height of tree
    }
    
        else
            return 1+countNodes(root->left)+countNodes(root->right);
        // T.C.- O(Log N)^2     First Log-for calculating heights 
       //                       Second Log-for calculating Nodes
    }
};