class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>mp;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end())  //element map mein present hai
            {
                for(auto x:mp[nums[i]])
                {
                    if((i*x)%k==0)
                        count++;
                }
            }
            mp[nums[i]].push_back(i);   //element ko map mein daal denge
        }
        return count;
    }
};