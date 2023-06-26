class Solution {
public:
    int n;
    const int MOD=1e9+7;
    int dp[101][201];   //{current_index,fuel}->yahi 2 parameters change ho rahe hain
    int solve(vector<int>& locations, int current_index, int destination, int fuel)
    {
        if(fuel<0)
            return 0;
        
        int ans=0;
        
        if(dp[current_index][fuel]!=-1)
            return dp[current_index][fuel];
        
        if(current_index==destination)
            ans+=1;
        
        for(int i=0;i<n;i++)
        {
            if(i!=current_index)
            {
                int remaining_fuel=fuel-abs(locations[i]-locations[current_index]);
                ans=(ans+solve(locations,i,destination,remaining_fuel))%MOD;
            }
        }
        return dp[current_index][fuel]=ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n=locations.size();
        memset(dp,-1,sizeof(dp));
        return solve(locations,start,finish,fuel);
    }
};