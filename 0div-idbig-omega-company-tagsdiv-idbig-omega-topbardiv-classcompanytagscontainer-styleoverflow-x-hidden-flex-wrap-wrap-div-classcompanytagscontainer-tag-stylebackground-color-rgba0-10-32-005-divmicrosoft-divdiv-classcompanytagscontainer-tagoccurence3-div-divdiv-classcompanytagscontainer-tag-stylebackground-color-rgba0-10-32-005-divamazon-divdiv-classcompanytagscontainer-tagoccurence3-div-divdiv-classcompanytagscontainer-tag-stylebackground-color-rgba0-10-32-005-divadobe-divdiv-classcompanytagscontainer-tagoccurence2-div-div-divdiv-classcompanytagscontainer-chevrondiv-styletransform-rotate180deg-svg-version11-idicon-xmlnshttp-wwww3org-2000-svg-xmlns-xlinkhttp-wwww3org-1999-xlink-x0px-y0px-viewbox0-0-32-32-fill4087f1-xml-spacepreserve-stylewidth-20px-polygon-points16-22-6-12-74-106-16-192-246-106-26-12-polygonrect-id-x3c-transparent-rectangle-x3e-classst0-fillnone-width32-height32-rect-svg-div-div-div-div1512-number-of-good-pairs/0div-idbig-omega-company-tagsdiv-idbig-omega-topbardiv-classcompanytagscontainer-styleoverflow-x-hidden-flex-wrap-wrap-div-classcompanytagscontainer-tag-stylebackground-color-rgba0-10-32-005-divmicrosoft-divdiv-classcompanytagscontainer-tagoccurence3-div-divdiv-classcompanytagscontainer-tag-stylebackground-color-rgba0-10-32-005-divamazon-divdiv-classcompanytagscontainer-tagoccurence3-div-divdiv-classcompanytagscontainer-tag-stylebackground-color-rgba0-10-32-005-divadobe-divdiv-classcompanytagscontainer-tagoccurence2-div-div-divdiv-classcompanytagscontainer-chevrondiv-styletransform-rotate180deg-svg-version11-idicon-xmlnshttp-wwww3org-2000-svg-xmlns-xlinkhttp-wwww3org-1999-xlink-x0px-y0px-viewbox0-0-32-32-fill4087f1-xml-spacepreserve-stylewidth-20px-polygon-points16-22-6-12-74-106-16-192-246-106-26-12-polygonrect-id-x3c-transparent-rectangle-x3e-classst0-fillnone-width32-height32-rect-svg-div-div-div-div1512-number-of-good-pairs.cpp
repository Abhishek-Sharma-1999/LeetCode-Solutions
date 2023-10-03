class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            count=count+mp[nums[i]];
            mp[nums[i]]++;
        }
        return count;
    }
};