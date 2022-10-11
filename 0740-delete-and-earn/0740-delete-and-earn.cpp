class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int> freq(n,0);
        vector<int> dp(n,0);
        for(auto i:nums)
        {
            freq[i]+=i;
        }
        
        dp[0]=0;
        dp[1]=freq[1];
        
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-2]+freq[i],dp[i-1]);
        }
        return dp[n-1];
    }
};