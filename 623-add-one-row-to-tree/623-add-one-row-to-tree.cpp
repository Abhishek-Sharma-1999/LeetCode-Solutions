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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1)
        {
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int Size=q.size();
            depth--;
            
            if(depth==0)
                break;
            while(Size--)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(depth==1)
                {
                    // For Left
                    if(curr->left!=NULL)
                    {
                        TreeNode* x=new TreeNode(val);
                        TreeNode* y=curr->left;
                        curr->left=x;
                        x->left=y;
                        q.push(x);
                    }
                    else
                    {
                        TreeNode* x=new TreeNode(val);
                        curr->left=x;
                        q.push(x);
                    }
                    
                    // For Right
                    if(curr->right!=NULL)
                    {
                        TreeNode* x=new TreeNode(val);
                        TreeNode* y=curr->right;
                        curr->right=x;
                        x->right=y;
                        q.push(x);
                    }
                    else
                    {
                        TreeNode* x=new TreeNode(val);
                        curr->right=x;
                        q.push(x);
                    }
                }
                
                else
                {
                    if(curr->left!=NULL)
                    {
                        q.push(curr->left);
                    }
                    if(curr->right!=NULL)
                    {
                        q.push(curr->right);
                    }
                }
                
            }
            
        }
        return root;
    }
};