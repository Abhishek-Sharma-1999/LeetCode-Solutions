class Solution {
public:
    int SolveMem(vector<int>& nums,int index,vector<int>& dp)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int incl=SolveMem(nums,index+2,dp)+nums[index];
        int excl=SolveMem(nums,index+1,dp)+0;
        
        dp[index]=max(incl,excl);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n+1,-1);
        return SolveMem(nums,0,ans);
    }
};