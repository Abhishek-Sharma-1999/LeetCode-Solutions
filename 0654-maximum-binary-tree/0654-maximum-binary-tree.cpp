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
    TreeNode* helper(vector<int>& nums,int start,int end)
    {
        if(start>end)
            return NULL;
        int maxi=INT_MIN,index=-1;
        for(int i=start;i<=end;i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                index=i;
            }
        }
        TreeNode *temp=new TreeNode(maxi);
        temp->left=helper(nums,start,index-1);
        temp->right=helper(nums,index+1,end);
        return temp;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};