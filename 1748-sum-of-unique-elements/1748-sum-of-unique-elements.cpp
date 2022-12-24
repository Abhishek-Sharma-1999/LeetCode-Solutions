class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int> mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        int ans=0;
        for(auto i:nums)
        {
            if(mp[i]==1)
                ans=ans+i;
        }
        return ans;
    }
};