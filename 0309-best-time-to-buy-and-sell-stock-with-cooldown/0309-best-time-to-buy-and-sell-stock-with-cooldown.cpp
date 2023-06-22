class Solution {
public:
    int dp[5001][2];
    int solve(vector<int>& prices,int n,int day,bool buy)
    {
        if(day>=n)
            return 0;
        if(dp[day][buy]!=-1)
            return dp[day][buy];
        int profit=0;
        if(buy) //buying
        {
            int consider=solve(prices,n,day+1,false)-prices[day];
            int not_consider=solve(prices,n,day+1,true);
            profit=max({profit,consider,not_consider});
        }
        else    //selling
        {
            int consider=solve(prices,n,day+2,true)+prices[day];
            int not_consider=solve(prices,n,day+1,false);
            profit=max({profit,consider,not_consider});
        }
        return dp[day][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,n,0,true);
    }
};