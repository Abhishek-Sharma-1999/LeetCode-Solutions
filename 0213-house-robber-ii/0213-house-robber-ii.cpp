class Solution {
public:
    int SolveTab(vector<int>& nums)
    {
        int dp[nums.size()+1];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return nums[0];
        }
        if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        
        vector<int>v1(nums.begin(),nums.end()-1); // First element se lekar second last tak
        vector<int>v2(nums.begin()+1,nums.end());
        
        return max(SolveTab(v1),SolveTab(v2));
    }
};