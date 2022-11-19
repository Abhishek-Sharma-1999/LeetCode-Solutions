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
    TreeNode* prev=NULL,*first=NULL,*middle=NULL,*last=NULL;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        inorder(root->left);    //Traversing Left
//previous ko hum har baar root ke equal kar rahe hain, isliye check karenge ki vo NULL ke equal na ho aur previous ki value abhi hum jis root par hain ussse badi ho 
        if(prev!=NULL && (prev->val > root->val))
        {
            if(first==NULL) //First Violation
            {
                first=prev;
                middle=root;
            }
// agar first NULL nahin hai, matlab pehla violation ho chuka hai toh last mein dusre violation ko daal denge             
            else    //Second Violation
            {
                last=root;
            }
        }
        prev=root;  // previous ko root bna dengle taali ,vo time-to-time updated rahe,next iteration ke liye
        
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(first!=NULL && last!=NULL)
        {
            swap(first->val,last->val);
        }
        else if(first!=NULL && middle!=NULL)
        {
            swap(first->val,middle->val);
        }
    }
};