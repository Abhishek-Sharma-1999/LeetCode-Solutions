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
    int maxPath=0;
    void solve(TreeNode* root,int steps,bool goLeft)
    {
        if(root==NULL)
            return ;
        maxPath=max(maxPath,steps);
      
        if(goLeft==true)    //Left jaana hai
        {
//toh root ke left mein chla gya,steps+1 kar diye aurgoLeft ko false kar diya ki ab left mein nahin jaana              
            solve(root->left,steps+1,false); 
// left jaana tha, lekin hum right chale gaye,toh stpes=1, se start honge aur goleft ko true kar denge             
            solve(root->right,1,true);
        }
        else    //Right Jaana hai
        {
// right jaana hai,aur right hi chale gaye,toh steps+1,aur phir ab left jaayenge toh goLeft=true            
            solve(root->right,steps+1,true);
// right jaana hai,lekin left left chale gaye,toh steps=1 ho jaayenge(phir se start karenge) aur goLeft=false;
            solve(root->left,1,false);
        }
        
    }
public:
    int longestZigZag(TreeNode* root) {
        if(root==NULL)
            return 0;
// ab starting mein pehle left jaaye ya right toh goLeft ko true false dono karenge
        solve(root,0,true); //pehle left
        solve(root,0,false);    //phir right
        return maxPath;
    }
};