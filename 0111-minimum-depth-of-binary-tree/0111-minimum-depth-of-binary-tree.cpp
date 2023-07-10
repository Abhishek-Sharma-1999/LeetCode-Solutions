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
    int minDepth(TreeNode* root) {
        // DFS ---------------------------------------
        if(root==NULL)
            return 0;
        if(root->left==NULL)    //agar root ka left,NULL hai toh right chale gaye
            return 1+minDepth(root->right);
        if(root->right==NULL) //agar root ka right NULL hai toh left chale gaye
            return 1+minDepth(root->left);
        return 1+min(minDepth(root->left),minDepth(root->right));   //hame minimum chaiye,jo left ya right se aayega (+1) jis root par hum currently hain
    
        
        // ----------------BFS------------------
        if(root==NULL)
            return 0;
        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        while(!q.empty())
        {
            TreeNode* u=q.front();
            q.pop();
            int n=q.size();
            while(n--)
            {
                if(u->left==NULL && u->right==NULL)
                    return level;
                if(u->left!=NULL)
                    q.push(root->left);
                if(u->right!=NULL)
                    q.push(root->right);
            }
            level++;
        }
        return -1;  //answer upar hi return kar diya hoga hamne
    }
};