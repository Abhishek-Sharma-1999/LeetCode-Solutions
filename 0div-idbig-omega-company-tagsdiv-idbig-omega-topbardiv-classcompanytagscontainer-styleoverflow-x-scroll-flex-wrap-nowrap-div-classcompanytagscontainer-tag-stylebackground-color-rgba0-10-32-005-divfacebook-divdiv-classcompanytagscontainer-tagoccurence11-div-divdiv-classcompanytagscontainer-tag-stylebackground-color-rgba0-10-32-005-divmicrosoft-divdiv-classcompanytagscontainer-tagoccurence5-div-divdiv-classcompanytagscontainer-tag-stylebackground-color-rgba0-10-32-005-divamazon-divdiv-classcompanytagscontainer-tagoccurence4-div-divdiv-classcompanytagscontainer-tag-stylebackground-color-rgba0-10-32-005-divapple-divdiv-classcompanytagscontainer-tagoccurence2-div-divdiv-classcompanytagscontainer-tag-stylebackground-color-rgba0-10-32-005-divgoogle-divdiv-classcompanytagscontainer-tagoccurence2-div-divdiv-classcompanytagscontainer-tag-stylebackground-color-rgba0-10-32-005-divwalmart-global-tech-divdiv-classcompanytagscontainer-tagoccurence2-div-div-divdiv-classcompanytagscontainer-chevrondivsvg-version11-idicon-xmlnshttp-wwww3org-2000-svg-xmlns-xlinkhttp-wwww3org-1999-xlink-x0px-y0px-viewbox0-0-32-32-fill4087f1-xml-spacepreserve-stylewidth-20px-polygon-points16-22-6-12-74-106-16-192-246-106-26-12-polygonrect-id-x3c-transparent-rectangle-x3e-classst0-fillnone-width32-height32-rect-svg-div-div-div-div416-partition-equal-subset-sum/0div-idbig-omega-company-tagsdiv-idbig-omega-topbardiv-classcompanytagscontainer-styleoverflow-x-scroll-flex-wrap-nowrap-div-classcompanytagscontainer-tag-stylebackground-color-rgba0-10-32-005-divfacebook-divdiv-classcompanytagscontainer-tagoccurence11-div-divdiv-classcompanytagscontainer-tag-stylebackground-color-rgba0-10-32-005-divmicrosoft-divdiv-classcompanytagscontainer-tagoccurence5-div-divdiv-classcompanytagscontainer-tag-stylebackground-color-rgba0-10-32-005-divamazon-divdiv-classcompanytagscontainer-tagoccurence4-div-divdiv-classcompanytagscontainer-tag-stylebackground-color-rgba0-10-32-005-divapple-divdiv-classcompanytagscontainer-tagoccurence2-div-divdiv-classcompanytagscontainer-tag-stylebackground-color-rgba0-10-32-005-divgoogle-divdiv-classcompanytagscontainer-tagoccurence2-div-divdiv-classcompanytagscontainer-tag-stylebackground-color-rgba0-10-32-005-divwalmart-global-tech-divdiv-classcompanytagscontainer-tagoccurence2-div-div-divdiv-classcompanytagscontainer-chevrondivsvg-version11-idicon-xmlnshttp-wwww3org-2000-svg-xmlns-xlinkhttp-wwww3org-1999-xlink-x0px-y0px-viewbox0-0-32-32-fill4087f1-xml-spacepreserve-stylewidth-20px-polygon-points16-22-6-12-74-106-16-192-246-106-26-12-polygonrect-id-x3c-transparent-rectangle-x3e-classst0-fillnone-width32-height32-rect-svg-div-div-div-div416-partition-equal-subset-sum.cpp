class Solution {
public:
    int solve_memoization(int index,vector<int>& nums,int N,int target,vector<vector<int>>&dp)
    {
        // base-case
        if(index>=N){
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int include=solve_memoization(index+1,nums,N,target-nums[index],dp);
        int exclude=solve_memoization(index+1,nums,N,target,dp);
        return dp[index][target]=include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int target=0;
        for(int i:nums)
        {
            target=target+i;
        }
        if(target%2==1){
            return 0;
        }
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return solve_memoization(0,nums,nums.size(),target/2,dp);
    }
};