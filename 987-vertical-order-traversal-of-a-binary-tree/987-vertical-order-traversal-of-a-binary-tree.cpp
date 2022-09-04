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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q; //(NODE,Vertical,Level)
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>> mp;
        while(q.size()!=0)
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto it=q.front().first;
                auto vert=q.front().second.first;
                auto levl=q.front().second.second;
                q.pop();
                mp[vert][levl].insert(it->val);
                if(it->left!=NULL)
                    q.push({it->left,{vert-1,levl+1}});
                if(it->right!=NULL)
                    q.push({it->right,{vert+1,levl+1}});
            }
        }
        
        for(auto i:mp)
        {
            vector<int>temp;
            for(auto j:i.second)
            {
                temp.insert(temp.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};