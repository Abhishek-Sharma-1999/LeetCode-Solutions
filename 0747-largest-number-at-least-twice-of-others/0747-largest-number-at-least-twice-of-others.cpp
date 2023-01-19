class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int Max=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>Max)
                Max=nums[i];
        }
        int ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==Max)
            {
                ans=i;
                continue;
            }
            if(nums[i]*2>Max)
                return -1;
        }
        return ans;
    }
};