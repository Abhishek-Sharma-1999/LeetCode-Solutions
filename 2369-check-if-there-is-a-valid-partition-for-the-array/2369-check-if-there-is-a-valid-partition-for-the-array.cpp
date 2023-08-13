class Solution {
public:
    bool solve_recusrion(int index,vector<int>& nums)
    {
        int n=nums.size();
        if(index>=n)
            return true;
        bool result=false;
        // Rule-1
        if(index+1 < n && nums[index]==nums[index+1])
        {
            result=result || solve_recusrion(index+2,nums);
        }
        // Rule-2
        if(index+2 < n &&nums[index]==nums[index+1] && nums[index+1]==nums[index+2])
        {
            result=result || solve_recusrion(index+3,nums);
        }
        // Rule-3
        if(index+2 < n && nums[index+1]-nums[index]==1 && nums[index+2]-nums[index+1]==1)
        {
            result=result || solve_recusrion(index+3,nums);
        }
        return result;
    }
    bool solve_memoization(int index,vector<int>& nums,vector<int>& dp)
    {
        int n=nums.size();
        if(index>=n) // partition karte hue,hum bahar nikal gaye array ke, matlab saare valid partition hue hain,toh true return kar denge
            return true;
        if(dp[index]!=-1)
            return dp[index];
        bool result=false;
        // Rule-1
        if(index+1 < n && nums[index]==nums[index+1])
        {
            result=result || solve_memoization(index+2,nums,dp);
        }
        // Rule-2
        if(index+2 < n &&nums[index]==nums[index+1] && nums[index+1]==nums[index+2])
        {
            result=result || solve_memoization(index+3,nums,dp);
        }
        // Rule-3
        if(index+2 < n && nums[index+1]-nums[index]==1 && nums[index+2]-nums[index+1]==1)
        {
            result=result || solve_memoization(index+3,nums,dp);
        }
        return dp[index]=result;
    }
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve_memoization(0,nums,dp);
    }
};