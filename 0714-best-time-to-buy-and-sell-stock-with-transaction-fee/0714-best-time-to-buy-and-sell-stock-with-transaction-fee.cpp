class Solution {
public:
    int dp[50001][2];
    int solve(vector<int>& prices, int fee,int day,int n,bool buy)
    {
        if(day>=n)
            return 0;
        int profit=0;
        if(dp[day][buy]!=-1)
            return dp[day][buy];
        if(buy) //agar buy kar rahe hain
        {
            int consider=solve(prices,fee,day+1,n,false)-prices[day];
            int not_consider=solve(prices,fee,day+1,n,true);
            profit=max({profit,consider,not_consider});
        }
        else    //sell
        {
            int consider=solve(prices,fee,day+1,n,true)+prices[day]-fee;
            int not_consider=solve(prices,fee,day+1,n,false);
            profit=max({profit,consider,not_consider});
        }
        return dp[day][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,fee,0,n,true);
    }
};