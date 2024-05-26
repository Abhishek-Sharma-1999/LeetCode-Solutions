class Solution {
    const int MOD=1e9+7;
    int dp[100001][2][3];
public:
    int solve(int n,int absent,int consecutive_late)
    {
        if(absent>=2 || consecutive_late>=3)
            return 0;
        if(n==0)
            return 1;
        if(dp[n][absent][consecutive_late]!=-1)
            return dp[n][absent][consecutive_late];
        int Present=solve(n-1,absent,0) % MOD;//present hai, toh consecutive late ki streak tut jaayegi, vo 0 ho jaayega
        int Absent=solve(n-1,absent+1,0) % MOD;//absent hai, toh consecutive late ki streak tut jaayegi, vo 0 ho jaayega
        int Late=solve(n-1,absent,consecutive_late+1) % MOD;//late hai, toh consecutive late ki streak jo bhi chal rahi hogi, usmein +1 ho jaayega
        return dp[n][absent][consecutive_late]=((Present+Absent)%MOD+Late)%MOD;
        
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0);
    }
};