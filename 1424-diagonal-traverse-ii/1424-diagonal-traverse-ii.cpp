class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                int diagonal=i+j;
                mp[diagonal].push_back(nums[i][j]);
            }
        }
        vector<int>ans;
        int i=0;
        while(mp.find(i)!=mp.end())
        {
            for(int &num:mp[i])
            {
                ans.push_back(num);
            }
            i++;
        }
        return ans;        
    }
};