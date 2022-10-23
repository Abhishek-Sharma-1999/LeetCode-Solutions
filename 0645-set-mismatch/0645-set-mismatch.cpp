class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        vector<int> ans;
        for(auto i:mp)
        {
            if(i.second==2)
            {
                ans.push_back(i.first);
            }
        }
        
        for(int i=1;i<=nums.size();i++)
        {
            if(mp[i]==0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};