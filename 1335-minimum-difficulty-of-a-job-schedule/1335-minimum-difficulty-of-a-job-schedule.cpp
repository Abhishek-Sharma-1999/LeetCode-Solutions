class Solution {
public:
    //RECURSION SOLUTION
    // int Rec(vector<int>& jobDifficulty,int n,int i,int d)
    // {
    //     if(d==1)
    //     {
    //         return *max_element(jobDifficulty.begin()+i,jobDifficulty.end());
    //     }
    //     int result=INT_MAX;
    //     int curr_d=INT_MIN; //Current Day-Dob Difficulty
    //     for(int j=i;j<=n-d;j++)
    //     {
    //         curr_d=max(curr_d,jobDifficulty[j]);
    //         result=min(result,curr_d+Rec(jobDifficulty,n,j+1,d-1));
    //     }
    //     return result;
    // }
    
    //MEMOIZATION SOLUTION
    int dp[301][11];
    int Mem(vector<int>& jobDifficulty,int n,int i,int d)
    {
        if(d==1)
        {
            return *max_element(jobDifficulty.begin()+i,jobDifficulty.end());
        }
        if(dp[i][d]!=-1)
        {
            return dp[i][d];
        }
        int result=INT_MAX;
        int curr_d=INT_MIN; //Current Day-Dob Difficulty
        for(int j=i;j<=n-d;j++)
        {
            curr_d=max(curr_d,jobDifficulty[j]);
            result=min(result,curr_d+Mem(jobDifficulty,n,j+1,d-1));
        }
        dp[i][d]=result;
        return dp[i][d];
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        memset(dp,-1,sizeof(dp));
        if(n<d)
            return -1;
        return Mem(jobDifficulty,n,0,d);
    }
};