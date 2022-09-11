class Solution {
public:
  int findminfromright(TreeNode* root){
        while(root->left!=nullptr)
            root=root->left;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        if(key > root->val)
        {
            root->right = deleteNode(root->right,key);
        }else if( key < root->val)
        {
            root->left = deleteNode(root->left,key);
        }else 
        { // we are at the key
           if(!root->left and !root->right)
           {
               delete(root);
               return NULL;
           }
           else if (!root->left or !root->right)
           {
               if(root->left)
               {
                   auto temp = root->left;
                   delete(root); 
                   return temp;
               }
               else 
               {
                    
                   auto temp = root->right;
                   delete(root); 
                   return temp;
               
               }
           }else 
           {
               root->val=findminfromright(root->right);
                root->right = deleteNode(root->right, root->val);
                
           }
        }
        
        return root;
    }
};